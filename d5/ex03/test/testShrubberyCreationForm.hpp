#include "test_utils.h"

TEST(ShrubberyCreationForm, constructorSetsToUnsigned){
	ShrubberyCreationForm a12r("name");

	ASSERT_EQ(false, a12r.getIsSigned());
}

TEST(ShrubberyCreationForm, cout){
	std::cout << ShrubberyCreationForm("form") << std::endl;
}

TEST(ShrubberyCreationForm, beSignedWithIncorrectGradeFails){
	ShrubberyCreationForm a325fjw("formWithHighGrade");
	Bureaucrat herrMueller("Thorsten", 148);

	ASSERT_ANY_THROW(a325fjw.beSigned(herrMueller));
	ASSERT_EQ(false, a325fjw.getIsSigned());
}

TEST(ShrubberyCreationForm, beSignedWithCorrectGradeSucceeds){
	ShrubberyCreationForm a325fjw("formWithLowGrade");
	Bureaucrat herrMueller("Thorsten", 1);

	a325fjw.beSigned(herrMueller);
	ASSERT_EQ(true, a325fjw.getIsSigned());
}

TEST(ShrubberyCreationForm, signingSignedFormThrows){
	ShrubberyCreationForm a325fjw("formWithLowGrade");
	Bureaucrat herrMueller("Thorsten", 1);

	a325fjw.beSigned(herrMueller);
	ASSERT_EQ(true, a325fjw.getIsSigned());
	ASSERT_ANY_THROW(a325fjw.beSigned(herrMueller));
}