//
// Created by fschlute on 5/24/22.
//

#include "Point.hpp"

Point::Point() : x(0), y(0) {

}

Point::Point(const Point &other) : x(other.x), y(other.y) {
	std::cout << "testestest";
	*this = other;
}

Point &Point::operator=(const Point &other) {
	(void) other;
	return *this;
}

Point::~Point() {

}

Point::Point(const float &x, const float &y) : x(x), y(y) {}

Fixed Point::getX(void) const{
	return (x);
}

Fixed Point::getY(void) const{
	return (y);
}