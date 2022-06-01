#include "test_utils.h"

TEST(intern, creatingNonExistantReturnsNull){
	Intern a;
	EXPECT_EQ(NULL, a.makeForm("nonExistingForm", "target"));
}

TEST(intern, creatingExistingClassReturnsNewInstanceOfForm){
	Intern a;
	Form *result = a.makeForm("PresidentialPardonForm", "target");
	EXPECT_TRUE(NULL != result);
	delete result;
}