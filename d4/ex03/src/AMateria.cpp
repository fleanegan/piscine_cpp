#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) :\
	type(type){
}

std::string const &AMateria::getType() const {
	return type;
}

//todo: why does this have to be non-pure virtual?!
void AMateria::use(ICharacter &target) {
	(void) target;
}

AMateria::AMateria() {

}

AMateria::~AMateria() {

}
