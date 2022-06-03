#include <iostream>
#include "Converter.hpp"

#ifndef TESTING

int main(int argc, char **argv){
	if (argc != 2)
		return 1;
	std::cout << Converter(argv[1]);
	return 0;
}

#endif
