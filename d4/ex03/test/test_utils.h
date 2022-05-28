#ifndef TEST_UTILS_H
# define TEST_UTILS_H

#include "gtest/gtest.h"
#include "../src/Animal.hpp"
#include <iostream>

Animal generateTestAnimal(){
	Animal a;
	Animal b(a);
	Animal c = b;
	return (c);
}

#endif	 // TEST_UTILS_H
