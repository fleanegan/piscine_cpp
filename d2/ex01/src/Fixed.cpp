//
// Created by fleanegan on 12.05.22.
//

#include <cmath>
#include "Fixed.h"


Fixed::Fixed(int value) : value(0){
	throwIfTooBig(value);
	setRawBits(value << fractionalBits);
}

Fixed::Fixed(float value) : value(0){
	float fractionalRest;

	throwIfTooBig((int)value);
	fractionalRest = getFractionalRest(value);
	storeSign(value);
	floatToBits(fractionalRest);
}

Fixed::Fixed(const Fixed &other){
	value = other.getRawBits();
	std::cout << "copy constructor" << std::endl;
	(void) other;
}

Fixed &Fixed::operator=(const Fixed &other){
	this->value = other.getRawBits();
	std::cout << "= operator" << std::endl;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "destructor" << std::endl;

}

Fixed::Fixed() : value(0){
	(void) fractionalBits;
	std::cout << "classic constructor" << std::endl;
}

// end of constructors

std::ostream& operator<<(std::ostream &os, Fixed &f) {
	os << f.toFloat();
	return os;
}


int Fixed::getRawBits() const {
	return value;
}

void Fixed::setRawBits(int value) {
	this->value = value;
}

int Fixed::toInt() const{
	return (value >> fractionalBits);
}

float Fixed::toFloat() const{
	float   result;

	result = 0;
	for (int i = 0; i < 31; ++i) {
		if (this->value & (1 << i))
		result += powf(2, (float)(i - fractionalBits));
	}
	if (this->value & 1 << 31)
		result *= -1.f;
	return (result);
}

void Fixed::throwIfTooBig(int value) const {
	if (std::fabs(value) > pow(2, 32 - fractionalBits))
		throw std::exception();
}

float Fixed::getFractionalRest(float newValue) {
	return fabsf(fabsf(newValue) - fabsf((float) toInt()));
}

void Fixed::storeSign(float newValue) {
	if (newValue < 0)
		value = value | 1 << 31;
}

void Fixed::floatToBits(float fractionalRest) {
	for (int i = 31; i > 0; --i) {
		float subtractor = powf(2, (float)(i - fractionalBits));
		if (fractionalRest >= subtractor)
		{
			fractionalRest -= subtractor;
			value = value | 1 << i;
		}
	}
}
