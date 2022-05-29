//
// Created by fleanegan on 28.05.22.
//

#include <iostream>
#include "Character.hpp"

Character::Character(const std::string &name) :\
		name(name), \
		inventory(){
	for (int i = 0; i < INVENTORY_MAX; ++i) {
		inventory[i] = NULL;
	}
}

Character::Character(const Character &other) : \
		inventory() {
	*this = other;
}

Character &Character::operator=(const Character &other) {
	if (this == &other)
		return *this;
	emptyInventory();
	for (int i = 0; i < INVENTORY_MAX; ++i) {
		inventory[i] = other.inventory[i];
	}
	name = other.name;
	return *this;
}

Character::~Character() {
	emptyInventory();
}

void Character::emptyInventory(){
	for (int i = 0; i < INVENTORY_MAX; ++i) {
		if (inventory[i] != NULL)
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
}

const std::string &Character::getName() const {
	return name;
}

void Character::equip(AMateria *m) {
	int i = 0;
	if (m == NULL)
	{
		std::cout << "This materia does not exist" << std::endl;
		return ;
	}
	while (i < INVENTORY_MAX && inventory[i] != NULL)
		i++;
	if (i < INVENTORY_MAX)
	{
		for (int j = 0; j < INVENTORY_MAX; ++j) {
			if (inventory[j] == m)
			{
				std::cout << m->getType() << "is already present on slot " << i << ", how would yout want to add it again?" << std::endl;
				return ;
			}
		}
		inventory[i] = m;
		std::cout << "equipped " << m->getType() << " on slot " << i << std::endl;
	}
	else
		std::cout << "inventory full" << std::endl;
}

void Character::unequip(int idx) {
	if (isIndexValid(idx)){
		std::cout << "throwing " << inventory[idx]->getType() << " from slot " << idx << " on the floor" << std::endl;
		delete inventory[idx];
		inventory[idx] = NULL;
	}
	else
		std::cout << "the index you entered does not lead to a valid materia" << std::endl;
}

void Character::use(int idx, ICharacter &target) {
	if (isIndexValid(idx))
	{
		std::cout << "using " << inventory[idx]->getType() << " at slot " << idx << " with address " << (void *) inventory[idx] << std::endl;
		inventory[idx]->use(target);
	}
	else
		std::cout << "the index you entered does not lead to a valid materia" << std::endl;
}

bool Character::isIndexValid(int idx) const {
	return idx < INVENTORY_MAX && idx >= 0 && inventory[idx] != NULL;
}
