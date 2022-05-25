#ifndef TESTING

#include <iostream>
#include "ClapTrap.h"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main( void ) {
	ClapTrap	t("brie de meaux");
	t.attack("Cantal");
	t.takeDamage(2);
	t.beRepaired(1022);

	ScavTrap	tf("Beaufort");
	tf.attack("Mimolette");
	tf.takeDamage(23);
	tf.guardGate();
	tf.beRepaired(2);

	FragTrap	tef("Vachequirit");
	tef.attack("Gorgonzola");
	tef.takeDamage(23);
	tef.beRepaired(2);
	return 0;
}
#endif
