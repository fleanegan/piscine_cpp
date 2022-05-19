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

TEST(test_fixed, constructor_from_float_positive_number){
	Fixed a(15.75f);
	ASSERT_FLOAT_EQ(a.toFloat(), 15.75);
}

TEST(test_fixed, constructor_from_int_get_as_float){
	Fixed a(-4);
	EXPECT_FLOAT_EQ( -4.f, a.toFloat());
	EXPECT_EQ(a.getRawBits(), -1024);
	std::bitset<32> x(a.getRawBits());
	std::cout << "float: "<< x << '\n';
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

TEST(test_fixed, write_to_stream2){
Fixed a(-2.75f);
testing::internal::CaptureStdout();
std::cout << a++;
std::string output = testing::internal::GetCapturedStdout();
EXPECT_STREQ(output.c_str(), "-2.75");
}

TEST(test_fixed, construct_without_invalue_assign){
	Fixed a;
	a.setRawBits(7<<6);
	ASSERT_FLOAT_EQ(1.75, a.toFloat());
}

TEST(test_fixed, compare){
	Fixed a(3.8f);
	Fixed b(-4);
	Fixed c(-4);

	ASSERT_EQ(a < b, false);
	ASSERT_EQ(a > b, true);
	ASSERT_EQ(a >= b, true);
	ASSERT_EQ(c >= b, true);
	ASSERT_EQ(c <= b, true);
	ASSERT_EQ(c == b, true);
	ASSERT_EQ(c != b, false);
	ASSERT_EQ(a != b, true);
}

TEST(test_fixed, basic_math){
	Fixed a(3.5f);
	Fixed b(-4);
	Fixed c(-4);

EXPECT_FLOAT_EQ(7.5f, (a - b).toFloat());
EXPECT_FLOAT_EQ(0.f, (c - b).toFloat());
EXPECT_FLOAT_EQ(-7.5f, (b - a).toFloat());
EXPECT_FLOAT_EQ(-0.5f, (a + b).toFloat());
EXPECT_FLOAT_EQ(-8.f, (c + b).toFloat());
EXPECT_FLOAT_EQ(3.5f, (b + a - c).toFloat());
EXPECT_FLOAT_EQ(16.f, (b * c).toFloat());
EXPECT_FLOAT_EQ(1.f, (b / c).toFloat());
}

TEST(test_fixed, post_incrementing_zero_leads_to_smallest_non_zero_fix_point_number){
	Fixed a(0);
	ASSERT_EQ(a++.getRawBits(), 0);
	ASSERT_EQ(a.getRawBits(), 1);
}

TEST(test_fixed, pre_incrementing_zero_leads_to_smallest_non_zero_fix_point_number){
	Fixed a(0);
	a++;
	ASSERT_EQ(a.getRawBits(), 1);
}

TEST(test_fixed, pre_decrementing_zero_correctly_shows_zero){
	Fixed a(0);
	ASSERT_EQ(a--.getRawBits(), 0);
	ASSERT_EQ(a.getRawBits(), -1);
}

TEST(test_fixed, post_decrementing_zero_correctly_shows_zero){
	Fixed a(0);
	--a;
	ASSERT_EQ(a.getRawBits(), -1);
}

TEST(test_fixed, get_min){
	Fixed a(0);
	Fixed b(1);
	ASSERT_EQ(Fixed::min(a, b), a);
}

TEST(test_fixed, get_max){
	Fixed a(0);
	Fixed b(1);
	ASSERT_EQ(Fixed::max(a, b), b);
}


#endif //TEST_CONTACT_H
