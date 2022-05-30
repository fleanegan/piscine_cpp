//
// Created by fleanegan on 28.05.22.
//

#include "Ice.hpp"

Ice::Ice() : \
		AMateria("ice"){
	std::cout<< "Ice constructor" << std::endl;
}

Ice::Ice(const Ice &other) : \
		AMateria("ice"){
	std::cout<< "Ice copy constructor" << std::endl;
	(void) other;
}

Ice &Ice::operator=(const Ice &other) {
	std::cout<< "Ice assignment" << std::endl;
	(void) other;
	return *this;
}

AMateria *Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice() {
	std::cout<< "Ice destroyed" << std::endl;
}
