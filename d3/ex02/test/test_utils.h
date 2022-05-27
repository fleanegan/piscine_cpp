#ifndef TEST_UTILS_H
# define TEST_UTILS_H

#include "gtest/gtest.h"
#include "../src/ClapTrap.h"
#include "../src/ScavTrap.hpp"
#include "../src/FragTrap.hpp"
#include <iostream>

ScavTrap getTestScavTrap(const std::string &name) {
	ScavTrap a(name);
	ScavTrap b(a);
	a = b;
	std::cout << "constructed test object: Done" << std::endl;
	return (a);
}

FragTrap getTestFragTrap(const std::string &name) {
	FragTrap a(name);
	FragTrap b(a);
	a = b;
	std::cout << "constructed test object: Done" << std::endl;
	return (a);
}

ClapTrap getTestClapTrap(const std::string &name) {
	ClapTrap a(name);
	ClapTrap b(a);
	a = b;
	std::cout << "constructed test object: Done" << std::endl;
	return (a);
}

#endif	 // TEST_UTILS_H
