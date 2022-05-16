//
// Created by fleanegan on 10.05.22.
//

#ifndef TEST_CONTACT_H
#define TEST_CONTACT_H
#include "test_utils.h"

TEST(test_string, copy_constructor){
Fixed a;
a.setRawBits(1);
Fixed b =a;
ASSERT_EQ(b.getRawBits(), 1);
}

TEST(test_string, assignment_operator){
Fixed a;
a.setRawBits(2);
Fixed b;
b=a;
ASSERT_EQ(b.getRawBits(), 2);
}

TEST(test_string, constructor_initializes_value_to_zero){
Fixed a;
ASSERT_EQ(a.getRawBits(), 0);
}

#endif //TEST_CONTACT_H
