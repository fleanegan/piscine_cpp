#include "test_utils.h"

TEST(testBsp, pointBelowTriangleReturnsFalse){
	ASSERT_FALSE(bsp(Point(0, 0), Point(2, 0), Point(1, 2), Point(1, -2)));
}

TEST(testBsp, pointRightToTriangleReturnsFalse){
	ASSERT_FALSE(bsp(Point(0, 0), Point(2, 0), Point(1, 2), Point(4, 0.5)));
}

TEST(testBsp, pointLeftToTriangleReturnsFalse){
	ASSERT_FALSE(bsp(Point(0, 0),  Point(2, 0), Point(1, 2),Point(-4, 0.5)));
}

TEST(testBsp, pointAboveTriangleReturnsFalse){
	ASSERT_FALSE(bsp(Point(0, 0), Point(1, 2), Point(2, 0), Point(1, 4.5)));
}

TEST(testBsp, pointOnEdgeReturnsFalse){
	ASSERT_FALSE(bsp(Point(0, 0), Point(1, 2), Point(2, 0), Point(1, 0)));
}

TEST(testBsp, zeroDimensionTriangleReturnsFalse){
	ASSERT_FALSE(bsp(Point(0, 0), Point(1, 0), Point(0, 2), Point(1, 0)));
}

TEST(testBsp, pointsDoNotHaveToBeInPositiveOrderOutside){
	Point a = Point(0,0);
	Point b = Point(2,0);
	Point c = Point(1,1);
	Point toTest = Point(3,0.5);
	ASSERT_FALSE(bsp(a, b, c, toTest));
	ASSERT_FALSE(bsp(a, c, b, toTest));
	ASSERT_FALSE(bsp(b, a, c, toTest));
	ASSERT_FALSE(bsp(b, c, a, toTest));
	ASSERT_FALSE(bsp(c, a, b, toTest));
	ASSERT_FALSE(bsp(c, b, a, toTest));
}

TEST(testBsp, pointsDoNotHaveToBeInPositiveOrderInside){
	Point a = Point(0,0);
	Point b = Point(2,0);
	Point c = Point(1,1);
	Point toTest = Point(0.5,0.25);
	ASSERT_TRUE(bsp(a, b, c, toTest));
	ASSERT_TRUE(bsp(a, c, b, toTest));
	ASSERT_TRUE(bsp(b, a, c, toTest));
	ASSERT_TRUE(bsp(b, c, a, toTest));
	ASSERT_TRUE(bsp(c, a, b, toTest));
	ASSERT_TRUE(bsp(c, b, a, toTest));
}

TEST(testBsp, pointInTriangleGetsDetected){
ASSERT_TRUE(bsp(Point(0, 0), Point(1, 2), Point(2, 0), Point(0.5, 0.5)));
}