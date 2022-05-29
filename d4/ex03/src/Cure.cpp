//
// Created by fleanegan on 28.05.22.
//

#include "Cure.hpp"

Cure::Cure() : \
	AMateria("cure"){
}

Cure::Cure(const Cure &other) : \
	AMateria("cure"){
	(void) other;
}

//todo: is there really nothing to copy?
Cure &Cure::operator=(const Cure &other) {
	(void) other;
	return *this;
}

Cure::~Cure() {
std::cout<< "cure destroyed \n\n";
}

AMateria *Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}