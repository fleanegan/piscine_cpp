//
// Created by fleanegan on 12.05.22.
//

#include "Fixed.h"

Fixed::Fixed(int value) : rawBits(value << fractionalBits){}

Fixed::Fixed(float value) : rawBits(roundf(value * (1 << fractionalBits ))){}

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

std::ostream& operator<<(std::ostream &os, const Fixed &f) {
	os << f.toFloat();
	return (os);
}


int Fixed::getRawBits() const {
	return (rawBits);
}

void Fixed::setRawBits(const int &value) {
	rawBits = value;
}

int Fixed::toInt() const{
	return (rawBits >> fractionalBits);
}

float Fixed::toFloat() const{
	return ((float)rawBits / (float)(1 << fractionalBits));
}

bool Fixed::operator<(const Fixed &other) const {
	if (rawBits < other.rawBits)
		return (true);
	return (false);
}

bool Fixed::operator>(const Fixed &other) const {
	if (rawBits > other.rawBits)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &other) const {
	if (rawBits >= other.rawBits)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &other) const {
	if (rawBits <= other.rawBits)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &other) const {
	if (rawBits == other.rawBits)
		return (true);
	return (false);
}

bool Fixed::operator==(const float other) const {
	if (rawBits == Fixed(other).rawBits)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &other) const {
	if (rawBits != other.rawBits)
		return (true);
	return (false);
}

Fixed Fixed::operator-(const Fixed &other) const {
	float tmp;

	tmp = toFloat() - other.toFloat();
	return (Fixed(tmp));
}

Fixed Fixed::operator+(const Fixed &other) const {
	float tmp;

	tmp = toFloat() + other.toFloat();
	return (Fixed(tmp));
}

Fixed Fixed::operator*(const Fixed &other) const {
	long long tmp;

	tmp = this->rawBits * other.rawBits;
	tmp = tmp >> fractionalBits;
	Fixed result;
	result.setRawBits((int)tmp);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const {
	float tmp;

	tmp = toFloat() / other.toFloat();
	return (Fixed(tmp));
}

const Fixed Fixed::operator++(int) {
	Fixed result;
	result.setRawBits(rawBits++);
	return (result);
}

Fixed& Fixed::operator++() {
	++rawBits;
	return (*this);
}

const Fixed Fixed::operator--(int) {
	Fixed result;
	result.setRawBits(rawBits--);
	return (result);
}

Fixed& Fixed::operator--() {
	--rawBits;
	return (*this);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.toFloat() > b.toFloat())
		return (const_cast<Fixed &>(a));
	return (const_cast<Fixed &>(b));
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}
