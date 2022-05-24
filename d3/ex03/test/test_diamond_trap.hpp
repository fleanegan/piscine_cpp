#include "test_utils.h"

TEST(testDiamondTrap, initVariablesAreSetCorrectly){
	DiamondTrapTester c("epoisses");

	ASSERT_EQ(100, c.getHitPoints());
	ASSERT_EQ(50, c.getEnergyPoints());
	ASSERT_EQ(30, c.getAttackDamage());
}

TEST(testDiamondTrap, attackingDoesNotRequireAnOpponentObject){
	DiamondTrapTester c("beaufort");
	c.attack("emmental");
}

TEST(testDiamondTrap, repairScavTrap){
	DiamondTrapTester c("mimolette");
	c.beRepaired(34);
}
