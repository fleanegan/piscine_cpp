//
// Created by fleanegan on 10.05.22.
//

#ifndef TEST_PHONE_BOOK_H
#define TEST_PHONE_BOOK_H
#include "test_utils.h"

TEST(test_phone_book, searching_phone_book_prints_nothing_if_nothing_found)
{
	PhoneBook b = PhoneBook();
	Contact contact_b("b", "b", "b", "b", "b");
	std::string str = "a";
	b.add_contact(contact_b);

	testing::internal::CaptureStdout();
	b.print_search_results(str);
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "");
}

TEST(test_phone_book, searching_phone_book_relevant_contacts)
{
	PhoneBook b = PhoneBook();
	Contact contact_a("a0", "a1", "a2", "a3", "a4");
	std::string str = "a";
	b.add_contact(contact_a);

	testing::internal::CaptureStdout();
	b.print_search_results(str);
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STRNE(output.c_str(), "");
}
// todo: add 

#endif //TEST_PHONE_BOOK_H
