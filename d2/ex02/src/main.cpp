#include "Fixed.h"

#ifndef TESTING

#include <iostream>
int main( void ) {
	for (int i = -10, j = -7; i < 100; i += 2, j+= 2) {
		float af = i * 0.2f;
		float bf = j * 0.45f;
		Fixed a = Fixed(af);
		Fixed b = Fixed(bf);

		std::cout << "af: " << af << " bf: " << bf << std::endl;
		std::cout << "operation: " << a << " + " << b << " = " << a + b << ((a + b == af + bf) ? " : ✅" : " : ❌") << std::endl;
		//std::cout << "debug    : " << af << " + " << bf << " = " << af + bf << std::endl;
		std::cout << "operation: " << a << " - " << b << " = " << a - b << ((a - b == af - bf) ? " : ✅" : " : ❌") << std::endl;
		//std::cout << "debug    : " << af << " - " << bf << " = " << af - bf << std::endl;
		std::cout << "operation: " << a << " * " << b << " = " << a * b << ((a * b == af * bf) ? " : ✅" : " : ❌") << std::endl;
		//std::cout << "debug    : " << af << " * " << bf << " = " << af * bf << std::endl;
		std::cout << "operation: " << a << " / " << b << " = " << a / b << ((a / b == af / bf) ? " : ✅" : " : ❌") << std::endl;
		//std::cout << "debug    : " << af << " / " << bf << " = " << af / bf << std::endl;

		if (i == 0)
			i = -1;
		if (j == 1)
			j = 0;
	}
	return 0;
}

#endif
