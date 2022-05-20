//
// Created by fleanegan on 12.05.22.
//

#include "Fixed.h"

Fixed::Fixed(int value) : value(0){
	throwIfTooBig(value);
	this->value = value << fractionalBits;
	storeSign(value);
}

Fixed::Fixed(float value) : value(0){
	throwIfTooBig((int)value);
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

std::ostream& operator<<(std::ostream &os, const Fixed &f) {
	os << f.toFloat();
	return (os);
}


int Fixed::getRawBits() const {
	return (value);
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

void Fixed::throwIfTooBig(int value) {
	if (std::fabs(value) > pow(2, 32 - fractionalBits))
		throw std::exception();
}

void Fixed::storeSign(float newValue) {
	if (newValue < 0)
		value = value | 1 << 31;
}

bool Fixed::operator<(const Fixed &other) const {
	if (toInt() < other.toInt())
		return (true);
	return (false);
}

bool Fixed::operator>(const Fixed &other) const {
	if (toInt() > other.toInt())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &other) const {
	if (toInt() >= other.toInt())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &other) const {
	if (toInt() <= other.toInt())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &other) const {
	if (toInt() == other.toInt())
		return (true);
	return (false);
}

bool Fixed::operator==(const float other) const {
	if (toInt() == Fixed(other).toInt())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &other) const {
	if (toInt() != other.toInt())
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

	tmp = this->getRawBits() * other.getRawBits();
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
	result.setRawBits(this->value++);
	return (result);
}

Fixed& Fixed::operator++() {
	++this->value;
	return (*this);
}

const Fixed Fixed::operator--(int) {
	Fixed result;
	result.setRawBits(this->value--);
	return (result);
}

Fixed& Fixed::operator--() {
	--this->value;
	return (*this);
}

Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.toInt() < b.toInt())
		return (const_cast<Fixed &>(a));
	return (const_cast<Fixed &>(b));
}

Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.toInt() > b.toInt())
		return (const_cast<Fixed &>(a));
	return (const_cast<Fixed &>(b));
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a.toInt() < b.toInt())
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a.toInt() > b.toInt())
		return (a);
	return (b);
}


