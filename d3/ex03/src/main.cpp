#ifndef TESTING

#include "DiamondTrap.hpp"

int main( void ) {
	DiamondTrap a("Diamond");
	std::cout << "Claptrap constructor " << a.getHitPoints() << " " << a.getAttackDamage() << " " << a.getEnergyPoints() << std::endl;
	return 0;
}

#endif
