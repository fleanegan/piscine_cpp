#include "test_utils.h"

TEST(form, constructorSetsToUnsigned){
	Form a12r("name", 90, 90);

	ASSERT_EQ(false, a12r.getIsSigned());
}

TEST(form, constructorWithGradeOverMaxThrows){
	ASSERT_ANY_THROW(Form("name", MAX_GRADE - 1, 12));
	ASSERT_ANY_THROW(Form("name", 12, MAX_GRADE - 1));
}

TEST(form, constructorWithGradeUnderMinThrows){
	ASSERT_ANY_THROW(Form("name", MIN_GRADE + 1, 12));
	ASSERT_ANY_THROW(Form("name", 12, MIN_GRADE + 1));
}

TEST(form, cout){
	std::cout << Form("form", 90, 90) << std::endl;
}

TEST(form, beSignedWithIncorrectGradeFails){
	Form a325fjw("formWithHighGrade", 25, 25);
	Bureaucrat herrMueller("Thorsten", 148);

	ASSERT_EQ(false, a325fjw.beSigned(herrMueller));
}

TEST(form, beSignedWithCorrectGradeFails){
	Form a325fjw("formWithLowGrade", 150, 15);
	Bureaucrat herrMueller("Thorsten", 148);

	ASSERT_EQ(true, a325fjw.beSigned(herrMueller));
}