//
// Created by fleanegan on 28.05.22.
//

#include "Character.hpp"

Character::Character(const std::string &name) :\
	name(name){

}

Character::Character(const Character &other) {
	*this = other;
}

Character &Character::operator=(const Character &other) {
	name = other.name;
	return *this;
}

Character::~Character() {

}

const std::string &Character::getName() const {
	return name;
}

void Character::equip(AMateria *m) {
	(void) m;
}

void Character::unequip(int idx) {
	(void) idx;
}

void Character::use(int idx, ICharacter &target) {
	(void) idx;
	(void) target;
}
