#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iterator>
#include "Span.hpp"

#ifndef TESTING

int main() {

	std::srand(unsigned(std::time(NULL)));
	std::vector<int> input(10);
	std::generate(input.begin(), input.end(), std::rand);
	std::copy(input.begin(),
			  input.end(),
			  std::ostream_iterator<int>(std::cout, " "));
	return 0;
}


#endif
