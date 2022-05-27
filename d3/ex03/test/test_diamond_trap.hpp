#include "test_utils.h"

TEST(testDiamondTrap, initVariablesAreSetToScavTrapSinceItIsCalledAfterFragTrap){
	DiamondTrap c = getTestDiamondTrap("epoisses");

	ASSERT_EQ(100, c.getHitPoints());
	ASSERT_EQ(50, c.getEnergyPoints());
	ASSERT_EQ(20, c.getAttackDamage());
}

TEST(testDiamondTrap, attackingDoesNotRequireAnOpponentObject){
	DiamondTrap c = getTestDiamondTrap("beaufort");
	c.attack("emmental");
}

TEST(testDiamondTrap, repairScavTrap){
	DiamondTrap c = getTestDiamondTrap("mimolette");
	c.beRepaired(34);
}
