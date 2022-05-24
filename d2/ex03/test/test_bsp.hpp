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

//TEST(testBsp, pointAboveTriangleReturnsFalse){
//	ASSERT_FALSE(bsp(Point(0, 0), Point(1, 2), Point(2, 0), Point(1, 4.5)));
//}
//
//TEST(testBsp, pointOnEdgeReturnsFalse){
//	ASSERT_FALSE(bsp(Point(0, 0), Point(1, 2), Point(2, 0), Point(1, 0)));
//}