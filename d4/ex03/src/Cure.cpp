//
// Created by fleanegan on 28.05.22.
//

#include "Cure.hpp"

Cure::Cure() : \
	AMateria("cure"){
}

Cure::Cure(const Cure &other) : \
	AMateria(other.getType()){

}

//todo: is there really nothing to copy?
Cure &Cure::operator=(const Cure &other) {
	(void) other;
	return *this;
}

Cure::~Cure() {

}

AMateria *Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter &target) {
	(void) target;
}