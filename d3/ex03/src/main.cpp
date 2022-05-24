#ifndef TESTING

#include "DiamondTrap.hpp"
#include <iostream>
int main( void ) {
	DiamondTrap a("Diamond");
	a.attack("brie");
	a.whoAmI();

	DiamondTrap b = a;
	b.beRepaired(10);
	b = a;
	b.beRepaired(10);
	return 0;
}

#endif
