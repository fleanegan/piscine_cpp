//
// Created by fleanegan on 10.05.22.
//

#ifndef TEST_CONTACT_H
#define TEST_CONTACT_H
#include "test_utils.h"

TEST(test_contact, adding_contact_with_empty_fields_throws)
{
	ASSERT_ANY_THROW(Contact c("", "", "", "", ""));
}

TEST(test_contact, searching_contact_returns_zero_if_not_relevant)
{
	Contact c("a", "a", "a", "a", "a");

	std::string searchString = "b";
	ASSERT_EQ(c.is_containing_search_string(searchString), 0);
}

TEST(test_contact, searching_contact_returns_one_if_relevant)
{
	Contact c("abc", "abc", "abc", "abc", "abc");

	std::string searchString = "b";
	ASSERT_EQ(c.is_containing_search_string(searchString), 1);
}

#endif //TEST_CONTACT_H
