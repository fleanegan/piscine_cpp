//
// Created by fleanegan on 28.05.22.
//

#include "Cure.hpp"

Cure::Cure() : \
	AMateria("cure"){
	std::cout<< "Cure constructor" << std::endl;
}

Cure::Cure(const Cure &other) : \
	AMateria("cure"){
	std::cout<< "Cure copy constructor" << std::endl;
	(void) other;
}

Cure &Cure::operator=(const Cure &other) {
	std::cout<< "Cure assignment" << std::endl;
	(void) other;
	return *this;
}

Cure::~Cure() {
	std::cout<< "Cure destroyed \n\n";
}

AMateria *Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}