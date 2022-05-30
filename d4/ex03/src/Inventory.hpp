//
// Created by fschlute on 5/30/22.
//

#ifndef EX03_INVENTORY_HPP
#define EX03_INVENTORY_HPP

#include "AMateria.hpp"

#define INVENTORY_MAX 4

class Inventory {
	AMateria *container[INVENTORY_MAX];
public:
	Inventory();
	Inventory(Inventory &other);
	Inventory &operator=(Inventory &);
	~Inventory();
	void emptyInventory();
	void add(AMateria *m);
	bool isInventoryFull();
	bool isMateriaAlreadyPresent(AMateria *pMateria);
	bool isIndexValid(int idx) const;
	AMateria *getMateriaByIndex(int i);
	void deleteMateriaByIndex(int i);
	AMateria * getMateriaByType(const std::string &basicString);
};

#endif //EX03_INVENTORY_HPP
