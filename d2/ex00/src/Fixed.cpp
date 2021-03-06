//
// Created by fleanegan on 12.05.22.
//

#include "Fixed.h"

Fixed::Fixed(const Fixed &other){
	if (DEBUG_ME)
		std::cout << "copy constructor" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other){
	rawBits = other.rawBits;
	if (DEBUG_ME)
		std::cout << "= operator" << std::endl;
	return (*this);
}

Fixed::~Fixed() {
	if (DEBUG_ME)
		std::cout << "destructor" << std::endl;
}

Fixed::Fixed() : rawBits(0){
	if (DEBUG_ME)
		std::cout << "classic constructor" << std::endl;
}

// end of constructors


int Fixed::getRawBits() const {
	return (rawBits);
}

void Fixed::setRawBits(const int &value) {
	rawBits = value;
}