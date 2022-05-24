#include "test_utils.h"

TEST(testScavTrap, initVariablesAreSetCorrectly){
	ScavTrapTester c("epoisses");

	ASSERT_EQ(100, c.getHitPoints());
	ASSERT_EQ(50, c.getEnergyPoints());
	ASSERT_EQ(20, c.getAttackDamage());
}

TEST(testScavTrap, attackingDoesNotRequireAnOpponentObject){
	ScavTrapTester c("beaufort");
	c.attack("emmental");
}

TEST(testScavTrap, repairScavTrap){
	ScavTrapTester c("mimolette");
	c.beRepaired(34);
}

TEST(testScavTrap, callingTheGuardGateFunction){
	ScavTrapTester c("roquefort");
	c.guardGate();
}

