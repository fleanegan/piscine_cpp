#include "test_utils.h"

TEST(testScavTrap, initVariablesAreSetCorrectly){
	ScavTrap c = getTestScavTrap("epoisses");

	ASSERT_EQ(100, c.getHitPoints());
	ASSERT_EQ(50, c.getEnergyPoints());
	ASSERT_EQ(20, c.getAttackDamage());
}

TEST(testScavTrap, attackingDoesNotRequireAnOpponentObject){
	ScavTrap c = getTestScavTrap("beaufort");
	c.attack("emmental");
}

TEST(testScavTrap, repairScavTrap){
	ScavTrap c = getTestScavTrap("mimolette");
	c.beRepaired(34);
}

TEST(testScavTrap, callingTheGuardGateFunction){
	ScavTrap c = getTestScavTrap("roquefort");
	c.guardGate();
}

