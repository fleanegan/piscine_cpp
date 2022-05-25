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
	ASSERT_FALSE(bsp(Point(0,0), Point(2,0), Point(1,1), Point(0.5,10.25)));
	ASSERT_FALSE(bsp(Point(0,0), Point(1,1), Point(2,0), Point(0.5,10.25)));
	ASSERT_FALSE(bsp(Point(2,0), Point(0,0), Point(1,1), Point(0.5,10.25)));
	ASSERT_FALSE(bsp(Point(2,0), Point(1,1), Point(0,0), Point(0.5,10.25)));
	ASSERT_FALSE(bsp(Point(1,1), Point(0,0), Point(2,0), Point(0.5,10.25)));
	ASSERT_FALSE(bsp(Point(1,1), Point(2,0), Point(0,0), Point(0.5,10.25)));
}

TEST(testBsp, pointsDoNotHaveToBeInPositiveOrderInside){
	ASSERT_TRUE(bsp(Point(0,0), Point(2,0), Point(1,1), Point(0.5,0.25)));
	ASSERT_TRUE(bsp(Point(0,0), Point(1,1), Point(2,0), Point(0.5,0.25)));
	ASSERT_TRUE(bsp(Point(2,0), Point(0,0), Point(1,1), Point(0.5,0.25)));
	ASSERT_TRUE(bsp(Point(2,0), Point(1,1), Point(0,0), Point(0.5,0.25)));
	ASSERT_TRUE(bsp(Point(1,1), Point(0,0), Point(2,0), Point(0.5,0.25)));
	ASSERT_TRUE(bsp(Point(1,1), Point(2,0), Point(0,0), Point(0.5,0.25)));
}

TEST(testBsp, pointInTriangleGetsDetected){
ASSERT_TRUE(bsp(Point(0, 0), Point(1, 2), Point(2, 0), Point(0.5, 0.5)));
}