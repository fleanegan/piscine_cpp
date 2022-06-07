#include <iostream>
#include "Array.hpp"

#ifndef TESTING

int main(){
	Array<int> a(2);
	a[0] = 42;
	a[1] = 43;
	std::cout << "int: " << a[0] << ", " << a[1] << std::endl;

	Array<std::string> b(2);
	b[0] = "bana";
	b[1] = "banana";
	std::cout << "string: " << b[0] << ", " << b[1] << std::endl;
	return 0;
}

#endif
