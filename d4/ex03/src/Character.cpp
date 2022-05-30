//
// Created by fleanegan on 28.05.22.
//

#include <iostream>
#include "Character.hpp"

Character::Character(const std::string &name) :\
		name(name), \
		inventory(){
	std::cout << "Character constructor" << std::endl;
}

Character::Character(Character &other) : \
		inventory() {
	std::cout << "Character copy constructor" << std::endl;
	*this = other;
}

Character &Character::operator=(Character &other) {
	std::cout << "Character assignment: >" << name << "< becomes: >" << other.name << "<" << std::endl;
	if (this == &other)
		return *this;
	inventory = other.inventory;
	name = other.name;
	return *this;
}

Character::~Character() {
	std::cout << "Character destructor" << std::endl;
}

const std::string &Character::getName() const {
	return name;
}

void Character::equip(AMateria *m) {
	int i = 0;
	try{
		inventory.add(m);
		std::cout << name << " equipped " << m->getType() << " with address: " << (void *) m << " on slot " << i << std::endl;
	}
	catch (const std::exception &e){
		std::cout << "could not add the materia to the inventory" << std::endl;
	}
}

void Character::unequip(int idx) {
	try{
		//fixme: to not do this !
		inventory.deleteMateriaByIndex(idx);
		std::cout << name << ": " << "throwing " << inventory.getMateriaByIndex(idx)->getType() << " from slot " << idx << " on the floor" << std::endl;
	}
	catch (const std::exception &exception) {
		std::cout << "cannot unequip" << std::endl;
	}
}

void Character::use(int idx, ICharacter &target) {
	AMateria *util;

	try{
		util = inventory.getMateriaByIndex(idx);
		std::cout << name << ": " << "using " << util->getType() << " at slot " << idx << " with address " << (void *) util << std::endl;
		util->use(target);
	}
	catch (const std::exception &e) {
		std::cout << "cannot use util at slot " << idx << std::endl;
	}
}