//
// Created by fleanegan on 10.05.22.
//

#ifndef TEST_CONTACT_H
#define TEST_CONTACT_H

#include <bitset>
#include "test_utils.h"

TEST(test_fixed, constructor_from_int){
	Fixed a(42);
	ASSERT_EQ(a.toInt(), 42);
	ASSERT_EQ(a.getRawBits(), 42 << 8);
}

TEST(test_fixed, constructor_from_int_to_big_for_Fixed_throws){
	ASSERT_ANY_THROW(Fixed((int)400000000200));
}

TEST(test_fixed, constructor_from_float){
	Fixed a(0.75f);
	ASSERT_FLOAT_EQ(a.toFloat(), 0.75);
}

TEST(test_fixed, constructor_from_float_for_negative_numbers){
	Fixed a(-0.75f);
	ASSERT_FLOAT_EQ(a.toFloat(), -0.75);
}

TEST(test_fixed, constructor_from_float_for_big_negative_numbers){
	Fixed a(-99915.75f);
	ASSERT_FLOAT_EQ(-99915.75, a.toFloat());
}

TEST(test_fixed, write_to_stream){
	Fixed a(-2.75f);
	testing::internal::CaptureStdout();
	std::cout << a;
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "-2.75");
}

TEST(test_fixed, construct_without_invalue_assign){
Fixed a;
a.setRawBits(7<<6);
ASSERT_FLOAT_EQ(1.75, a.toFloat());
}


#endif //TEST_CONTACT_H
