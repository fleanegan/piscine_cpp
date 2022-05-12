//
// Created by fleanegan on 10.05.22.
//

#ifndef TEST_CONTACT_H
#define TEST_CONTACT_H
#include "test_utils.h"

TEST(test_string, find_pos_of_string)
{
	std::string big = "This is a test, my camembert test feels a little weak but my epoisses test is strapping";
	const std::string search_string = "test";
	const std::string replace_string = "amabogdilla";
	size_t i = big.find(search_string);
	EXPECT_EQ(i, 10);
	auto d = big.find("safsegfeag", 3);
	EXPECT_EQ(d, std::string::npos);
	std::string first_occurence = big.substr(i);
	std::string after_first_occurence = first_occurence.substr(search_string.length());
	ASSERT_STREQ(after_first_occurence.c_str(), ", my camembert test feels a little weak but my epoisses test is strapping");
}



TEST(test_string, return_input_if_replacee_not_found){
	std::string	res = substitute("bananana is no juice", "test", "bread");

	ASSERT_STREQ(res.c_str(), "bananana is no juice");
}


TEST(test_string, return_replacer_if_input_equals_replacee){
	std::string	res = substitute("test", "test", "bread");

	ASSERT_STREQ(res.c_str(), "bread");
}

TEST(test_string, substitute_one_occurence_at_beginning){
	std::string	res = substitute("test me", "test", "bread");

	ASSERT_STREQ(res.c_str(), "bread me");
}

TEST(test_string, substitute_one_occurence_in_the_middle){
	std::string	res = substitute("now test me", "test", "bread");

	ASSERT_STREQ(res.c_str(), "now bread me");
}

TEST(test_string, substitute_one_occurence_at_the_end){
	std::string	res = substitute("now me test", "test", "bread");

	ASSERT_STREQ(res.c_str(), "now me bread");
}


TEST(test_string, substitute_multiple){
	std::string	res = substitute("test now test me test", "test", "bread");

	ASSERT_STREQ(res.c_str(), "bread now bread me bread");
}

#endif //TEST_CONTACT_H
