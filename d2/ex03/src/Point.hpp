//
// Created by fschlute on 5/24/22.
//

#ifndef EX03_POINT_HPP
#define EX03_POINT_HPP

#include "Fixed.h"

class Point {
private:
	Fixed const x;
	Fixed const y;
public:
	Point();
	Point(const float &x, const float &y);
	Point(const Point &other);
	Point &operator=(const Point &);
	~Point();

	Fixed getX(void) const;
	Fixed getY(void) const;
};

#endif //EX03_POINT_HPP
