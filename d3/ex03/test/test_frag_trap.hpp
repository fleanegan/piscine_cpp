#include "test_utils.h"

TEST(testFragTrap, initVariablesAreSetCorrectly){
FragTrapTester c("Geramont");

ASSERT_EQ(100, c.getHitPoints());
ASSERT_EQ(100, c.getEnergyPoints());
ASSERT_EQ(30, c.getAttackDamage());
}

TEST(testFragTrap, attacking){
	FragTrap c("Caprice des dieux");
	c.attack("Vachequirit");
}

TEST(testFragTrap, highFive){
	FragTrap c("Buche de chevre");
	c.highFivesGuys();
}
