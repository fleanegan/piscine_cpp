//
// Created by fleanegan on 12.05.22.
//

#include <cmath>
#include "Fixed.h"


Fixed::Fixed(int value) : value(0){
	this->value = value << fractionalBits;
	storeSign(value);
}

Fixed::Fixed(float value) : value(0){
	this->value = roundf(value * (1 << fractionalBits ));
}

Fixed::Fixed(const Fixed &other){
	value = other.getRawBits();
	if (DEBUG_ME)
		std::cout << "copy constructor" << std::endl;
	(void) other;
}

Fixed &Fixed::operator=(const Fixed &other){
	this->value = other.getRawBits();
	if (DEBUG_ME)
		std::cout << "= operator" << std::endl;
	return (*this);
}

Fixed::~Fixed() {
	if (DEBUG_ME)
		std::cout << "destructor" << std::endl;
}

Fixed::Fixed() : value(0){
	(void) fractionalBits;
	if (DEBUG_ME)
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
	return ((float)this->value / (float)(1 << fractionalBits));
}

void Fixed::storeSign(float newValue) {
	if (newValue < 0)
		value = value | 1 << 31;
}