//
// Created by fleanegan on 28.05.22.
//

#ifndef EX03_CURE_HPP
#define EX03_CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria{
public:
	Cure();
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	~Cure();

	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif //EX03_CURE_HPP
