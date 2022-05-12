//
// Created by fleanegan on 10.05.22.
//

#ifndef TEST_CONTACT_H
#define TEST_CONTACT_H
#include "test_utils.h"

TEST(test_human_b, attack_without_weapon)
{
	HumanB b("Bert");

	testing::internal::CaptureStdout();
	b.attack();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "Bert attacks with their bare hands\n");
}

TEST(test_human_b, attack_with_weapon)
{
	HumanB b("Bert");
	Weapon w("Camembert");
	b.setWeapon(w);

	testing::internal::CaptureStdout();
	b.attack();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "Bert attacks with their Camembert\n");
}

TEST(test_human_b, modifying_weapon_after_setting_works)
{
	HumanB b("Bert");
	Weapon w("Camembert");
	b.setWeapon(w);
	w.setType("Epoisses");

	testing::internal::CaptureStdout();
	b.attack();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "Bert attacks with their Epoisses\n");
}

TEST(test_human_b, copy_constructor_updates_weapon)
{
	HumanB b("Bert");
	Weapon w("Camembert");
	b.setWeapon(w);

	HumanB c = b;

	testing::internal::CaptureStdout();
	c.attack();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "Bert attacks with their Camembert\n");
}

TEST(test_human_a, always_armed)
{
	Weapon w("Camembert");
	HumanA b("Bert", w);

	testing::internal::CaptureStdout();
	b.attack();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "Bert attacks with their Camembert\n");
}


#endif //TEST_CONTACT_H
