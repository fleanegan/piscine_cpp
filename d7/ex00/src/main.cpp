#include <iostream>
#include "Functions.hpp"

#ifndef TESTING

int main(){
	int a = 4;
	int b = 3;

	if (min(a, b) != 3)
		std::cout << "wrong" << std::endl;
	if (max(a, b) != 4)
		std::cout << "wrong" << std::endl;
	swap(a, b);
	if (a != 3 || b != 4)
		std::cout << "wrong" << std::endl;
	return 0;
}

#endif
