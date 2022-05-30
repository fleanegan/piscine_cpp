//
// Created by fleanegan on 28.05.22.
//

#ifndef EX03_MATERIASOURCE_HPP
#define EX03_MATERIASOURCE_HPP

#include "IMaterialSource.hpp"
#include "Inventory.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource{
private:
	Inventory inventory;
public:
	MateriaSource();
	MateriaSource(MateriaSource &other);
	MateriaSource &operator=(MateriaSource &other);
	virtual ~MateriaSource();

	virtual void learnMateria(AMateria *materia);
	virtual AMateria *createMateria(const std::string &type);
};

#endif //EX03_MATERIASOURCE_HPP
