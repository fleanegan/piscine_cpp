//
// Created by fleanegan on 28.05.22.
//

#ifndef EX03_MATERIASOURCE_HPP
#define EX03_MATERIASOURCE_HPP

#include "IMaterialSource.hpp"

class MateriaSource : public IMateriaSource{
public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	virtual ~MateriaSource();

	virtual void learnMateria(AMateria *materia);
	virtual AMateria *createMateria(const std::string &type);
};

#endif //EX03_MATERIASOURCE_HPP
