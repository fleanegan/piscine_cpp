#ifndef TESTING

#include <iostream>
#include "ClapTrap.h"
int main( void ) {
	ClapTrap	t("brie de meaux");
	t.attack("Cantal");
	t.takeDamage(2);
	t.beRepaired(1022);
	return 0;
}

#endif
