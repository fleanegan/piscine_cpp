#include "Point.hpp"

//todo: does direction matter?
int	isOnPositiveSide(const Point &p1, const Point &p2, const Point &pToTest){
	Fixed result = ((pToTest.getX() - p1.getX() * (p2.getY() - p1.getY())) \
			- (pToTest.getY() - p1.getY() * (p2.getX() - p1.getX())));
	if (result.toFloat() > 0)
		return (1);
	if (result.toFloat() < 0)
		return (-1);
	return (0);
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	int firstBorder = isOnPositiveSide(a, b, point);
	int secondBorder = isOnPositiveSide(b, c, point);
	int thirdBorder = isOnPositiveSide(c, a, point);

	std::cout << "1: " << firstBorder << " 2: " << secondBorder << " 3: " << thirdBorder << std::endl;


	bool has_neg = (firstBorder < 0 || (secondBorder < 0)) || (thirdBorder < 0);
	bool has_pos = (firstBorder > 0 || (secondBorder > 0)) || (thirdBorder > 0);

	return !(has_neg && has_pos);
//
//	if ((firstBorder <= Fixed(0.f) && secondBorder <= Fixed(0.f) && thirdBorder <= Fixed(0.f)) \
//		|| (firstBorder >= Fixed(0.f) && secondBorder >= Fixed(0.f) && thirdBorder >= Fixed(0.f)))
//		return (false);
//	return (true);
}