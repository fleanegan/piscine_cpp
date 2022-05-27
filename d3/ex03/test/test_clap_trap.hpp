#include "test_utils.h"

TEST(test_clap_trap, init_variables_are_set_correctly){
	ClapTrap c = getTestClapTrap("cantal");

	ASSERT_EQ(10, c.getHitPoints());
	ASSERT_EQ(10, c.getEnergyPoints());
	ASSERT_EQ(0, c.getAttackDamage());
}

TEST(test_clap_trap, ct_looses_one_energy_point_on_attack){
	ClapTrap c = getTestClapTrap("fourme dalambert");
	int energyPointsInit = c.getEnergyPoints();

	c.attack("camembert");

	ASSERT_EQ(energyPointsInit - 1, c.getEnergyPoints());
}

TEST(test_clap_trap, if_no_energy_left_cannot_attack){
	ClapTrap c = getTestClapTrap("reblochon");
	c.setEnergyPoints(0);

	c.attack("camembert");

	ASSERT_EQ(0, c.getEnergyPoints());
}

TEST(test_clap_trap, negative_health_points_are_fixed_to_zero){
	ClapTrap c = getTestClapTrap("reblochon");

	c.takeDamage(c.getHitPoints() + 1);

	ASSERT_EQ(0, c.getHitPoints());
}

TEST(test_clap_trap, cannot_attack_when_dead){
	ClapTrap c = getTestClapTrap("reblochon");
	int energyPointsInit = c.getEnergyPoints();
	c.setHitPoints(0);

	c.attack("tomme de chevre");

	ASSERT_EQ(energyPointsInit, c.getEnergyPoints());
}


TEST(test_clap_trap, reparing_can_increase_hit_points_over_init){
	ClapTrap c = getTestClapTrap("brillat-savarin");
	int hitPointsInit = c.getHitPoints();

	c.beRepaired(1);

	ASSERT_EQ(hitPointsInit + 1, c.getHitPoints());
}

TEST(test_clap_trap, if_no_energy_left_cannot_repair){
	ClapTrap c = getTestClapTrap("maroilles");
	int hitPointsInit = c.getHitPoints();
	c.setEnergyPoints(0);

	c.beRepaired(1);

	ASSERT_EQ(hitPointsInit, c.getHitPoints());
}