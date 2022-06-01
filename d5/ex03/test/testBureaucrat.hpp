#include "test_utils.h"

TEST(bureaucrat, initGradeTooLowThrowsException){
	try {
		Bureaucrat jp("jp", MIN_GRADE + 1);
		FAIL() << "Expected Exception";
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
		Bureaucrat jp("jp", MAX_GRADE - 1);
		FAIL() << "Expected Exception";
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

TEST(bureaucrat, incremetingDegreeAndDecrementingGradeReturnsSame){
	Bureaucrat jp("jp", 25);
	EXPECT_EQ(25, jp.getGrade());

	jp.incrementGrade();
	EXPECT_EQ(24, jp.getGrade());
	jp.decrementGrade();
	EXPECT_EQ(25, jp.getGrade());
}

TEST(bureaucrat, degrementingGradeOverMaxThrows){
	Bureaucrat jp("jp", MAX_GRADE);

	try {
		jp.incrementGrade();
		FAIL() << "Expected Exception";
	}
	catch(GradeTooHighException const & err) {
		SUCCEED	();
	}
	catch(...) {
		FAIL() << "Expected GradeTooHighException";
	}
}


TEST(bureaucrat, degrementingGradeUnderMinThrows){
	Bureaucrat jp("jp", MIN_GRADE);

	try {
		jp.decrementGrade();
		FAIL() << "Expected Exception";
	}
		catch(GradeTooLowException const & err) {
		SUCCEED	();
	}
	catch(...) {
		FAIL() << "Expected GradeTooLowException";
	}
}

TEST(bureaucrat, cout){
	Bureaucrat jp("jp", 25);

	std::cout << jp << std::endl;
}

TEST(bureaucrat, signFormSuccess){
	Bureaucrat jp("jp", 25);
	ShrubberyCreationForm yi904i44("Tartiflette");

	ASSERT_EQ(true, jp.signForm(yi904i44));
}

TEST(bureaucrat, signFormFailure){
	Bureaucrat jp("jp", 150);
	ShrubberyCreationForm yi904i44("Hardie");

	ASSERT_EQ(false, jp.signForm(yi904i44));
}

TEST(bureaucrat, executeFormFailure){
	Bureaucrat jp("jp", 1);
	Bureaucrat jc("jp", 150);
	ShrubberyCreationForm yi904i44("Hardie");
	jp.signForm(yi904i44);

	ASSERT_EQ(false, jc.executeForm(yi904i44));
}

TEST(bureaucrat, executeFormSuccess){
	Bureaucrat jp("jp", 1);
	ShrubberyCreationForm yi904i44("Hardie");
	jp.signForm(yi904i44);

	ASSERT_EQ(true, jp.executeForm(yi904i44));
}