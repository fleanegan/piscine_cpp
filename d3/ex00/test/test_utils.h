#ifndef TEST_UTILS_H
# define TEST_UTILS_H

#include "gtest/gtest.h"
#include "../src/ClapTrap.h"
#include <iostream>

ClapTrap getTestClapTrap(const std::string &name) {
	ClapTrap a(name);
	ClapTrap b(a);
	a = b;
	std::cout << "constructed test object: Done" << std::endl;
	return (a);
}

#endif	 // TEST_UTILS_H
