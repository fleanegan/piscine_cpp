#ifndef TEST_UTILS_H
# define TEST_UTILS_H

#include "gtest/gtest.h"
#include "../src/ClapTrap.h"
#include "../src/ScavTrap.hpp"
#include "../src/FragTrap.hpp"
#include "../src/DiamondTrap.hpp"
#include <iostream>

DiamondTrap getTestDiamondTrap(const std::string &name) {
	DiamondTrap a(name);
	DiamondTrap b(a);
	DiamondTrap c = b;
	std::cout << "constructed test object: Done" << std::endl;
	return (c);
}

ScavTrap getTestScavTrap(const std::string &name) {
	ScavTrap a(name);
	ScavTrap b(a);
	ScavTrap c = b;
	std::cout << "constructed test object: Done" << std::endl;
	return (c);
}

FragTrap getTestFragTrap(const std::string &name) {
	FragTrap a(name);
	FragTrap b(a);
	FragTrap c = b;
	std::cout << "constructed test object: Done" << std::endl;
	return (c);
}

ClapTrap getTestClapTrap(const std::string &name) {
	ClapTrap a(name);
	ClapTrap b(a);
	ClapTrap c = b;
	std::cout << "constructed test object: Done" << std::endl;
	return (c);
}

#endif	 // TEST_UTILS_H
