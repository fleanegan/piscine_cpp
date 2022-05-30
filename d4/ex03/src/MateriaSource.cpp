//
// Created by fleanegan on 28.05.22.
//

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() :\
		inventory(){
	std::cout << "MaterialSource constructor" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource &other) {
	std::cout << "MaterialSource copy constructor" << std::endl;
	*this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource &other) {
	std::cout << "MaterialSource assignment" << std::endl;
	if (this == &other)
		return *this;
	inventory = other.inventory;
	return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << "MaterialSource destructor" << std::endl;
}

void MateriaSource::learnMateria(AMateria *materia) {
	try{
		inventory.add(materia);
	}
	catch (const std::exception &exception) {
		delete materia;
	}
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	try{
		return inventory.getMateriaByType(type)->clone();
	}
	catch (const std::exception &exception) {
		std::cout << "I do not know this material" << std::endl;
	}
	return NULL;
}

