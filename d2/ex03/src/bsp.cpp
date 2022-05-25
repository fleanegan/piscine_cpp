#include "Point.hpp"

//todo: does direction matter?
int	isOnPositiveSide(const Point &p1, const Point &p2, const Point &pToTest){
	Fixed p1_pToTest_x = pToTest.getX() - p1.getX();
	Fixed p1_p2_y = p2.getY() - p1.getY();
	Fixed p1_pToTest_y = pToTest.getY() - p1.getY();
	Fixed p1_p2_x = p2.getX() - p1.getX();
	Fixed result = ((p1_pToTest_x * p1_p2_y) - (p1_pToTest_y * p1_p2_x));
	if (result.getRawBits() == 0)
		return (0);
	if (result.toFloat() > 0)
		return (1);
	return (-1);
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	int firstBorder = isOnPositiveSide(a, b, point);
	int secondBorder = isOnPositiveSide(b, c, point);
	int thirdBorder = isOnPositiveSide(c, a, point);

	if ((Fixed(firstBorder) < Fixed(0.f) && Fixed(secondBorder) < Fixed(0.f) && Fixed(thirdBorder) < Fixed(0.f)) \
		|| (Fixed(firstBorder) > Fixed(0.f) && Fixed(secondBorder) > Fixed(0.f) && Fixed(thirdBorder) > Fixed(0.f)))
		return (true);
	return (false);
}