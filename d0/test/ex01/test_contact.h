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
	ASSERT_EQ(c.isContainingSearchString(searchString), 0);
}

TEST(test_contact, searching_contact_returns_one_if_relevant)
{
	Contact c("abc", "abc", "abc", "abc", "abc");

	std::string searchString = "b";
	ASSERT_EQ(c.isContainingSearchString(searchString), 1);
}

TEST(test_contact, print_contact_all_fields_len_1)
{
	Contact c("a", "b", "c", "d", "e");

	testing::internal::CaptureStdout();
	c.showOverview();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "|         a|         b|         c|\n");
}

TEST(test_contact, print_contact_all_fields_shorter_than_10)
{
	Contact c("abc", "b", "c", "d", "efg");

	testing::internal::CaptureStdout();
	c.showOverview();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "|       abc|         b|         c|\n");
}

TEST(test_contact, print_contact_if_field_longer_than_10_trunc)
{
	Contact c("0123456789xxxxxxx", "b", "c", "d", "efg");

	testing::internal::CaptureStdout();
	c.showOverview();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "|012345678.|         b|         c|\n");
}

#endif //TEST_CONTACT_H
