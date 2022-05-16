//
// Created by fleanegan on 12.05.22.
//

#include "Fixed.h"

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

int Fixed::getRawBits() const {
	return value;
}

void Fixed::setRawBits(int value) {
	this->value = value;
}
