//
// Created by fschlute on 5/30/22.
//

#include <iostream>
#include "Inventory.hpp"

Inventory::Inventory() :\
		container(){
	std::cout << "Inventory constructor" << std::endl;
}

Inventory::Inventory(Inventory &other) {
	std::cout << "Inventory copy constructor" << std::endl;
	*this = other;
}

Inventory &Inventory::operator=(Inventory &other) {
	std::cout << "Inventory assignment" << std::endl;
	if (this == &other)
		return *this;
	emptyInventory();
	for (int i = 0; i < INVENTORY_MAX; ++i) {
		container[i] = other.container[i];
		other.container[i] = NULL;
	}
	return *this;
}

Inventory::~Inventory() {
	std::cout << "Inventory destructor" << std::endl;
	emptyInventory();
}

void Inventory::emptyInventory(){
	for (int i = 0; i < INVENTORY_MAX; ++i) {
		if (container[i] != NULL)
		{
			std::cout << "Deleting " << container[i]->getType() << " at address: " << (void *) container[i] << std::endl;
			delete container[i];
			container[i] = NULL;
		}
	}
}

void Inventory::add(AMateria *m) {
	int i = 0;
	if (m == NULL)
	{
		std::cout << "This materia does not exist" << std::endl;
		throw std::exception();
	}
	if (isInventoryFull() || isMateriaAlreadyPresent(m))
		throw std::exception();
	while (i < INVENTORY_MAX && container[i] != NULL)
		i++;
	container[i] = m;
	std::cout << "added " << m->getType() << " with address: " << (void *) m << "to inventory on slot " << i << std::endl;
}

bool Inventory::isInventoryFull() {
	for (int j = 0; j < INVENTORY_MAX; ++j) {
		if (container[j] == NULL)
			return false;
	}
	return true;
}

bool Inventory::isMateriaAlreadyPresent(AMateria *pMateria){
	for (int j = 0; j < INVENTORY_MAX; ++j)
		if (container[j] == pMateria)
		{
			std::cout << pMateria->getType() << " is already present on slot " << j << ", how would yout want to add it again?" << std::endl;
			return true;
		}
	return false;
}

bool Inventory::isIndexValid(int idx) const {
	return idx < INVENTORY_MAX && idx >= 0 && container[idx] != NULL;
}

AMateria *Inventory::getMateriaByIndex(int i){
	if (isIndexValid(i))
		return container[i];
	std::cout << "the index you entered does not lead to a valid materia" << std::endl;
	throw std::exception();
}

void Inventory::removeMateriaByIndex(int i){
	AMateria *toBeRemoved;

	try {
		toBeRemoved = getMateriaByIndex(i);
		container[i] = NULL;
	}
	catch (const std::exception &e){
		std::cout << "could not delete materia on slot " << i << std::endl;
	}
}

AMateria * Inventory::getMateriaByType(const std::string &basicString) {
	for (int i = 0; i < INVENTORY_MAX; ++i) {
		if (isIndexValid(i) && basicString == container[i]->getType())
			return container[i];
	}
	std::cout << "The materia '" << basicString << "' is not present in the inventory" << std::endl;
	throw std::exception();
}
