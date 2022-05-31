#include "test_utils.h"

TEST(bureaucrat, initGradeTooLowThrowsException){
	try {
		Bureaucrat jp("jp", 151);
		FAIL() << "Expected std::out_of_range";
		}
	catch(GradeTooLowException const & err) {
		SUCCEED	();
	}
	catch(...) {
		FAIL() << "Expected GradeTooLowException";
	}
}

TEST(bureaucrat, initGradeTooHighThrowsException){
	try {
		Bureaucrat jp("jp", 0);
		FAIL() << "Expected std::out_of_range";
	}
	catch(GradeTooHighException const & err) {
		SUCCEED	();
	}
	catch(...) {
		FAIL() << "Expected GradeTooHighException";
	}
}

TEST(bureaucrat, getName){
Bureaucrat jp("jp", 1);

EXPECT_STREQ("jp", jp.getName().c_str());
}


TEST(bureaucrat, getGrade){
Bureaucrat jp("jp", 25);

EXPECT_EQ(25, jp.getGrade());
}