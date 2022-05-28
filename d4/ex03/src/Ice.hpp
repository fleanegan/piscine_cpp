//
// Created by fleanegan on 28.05.22.
//

#ifndef EX03_ICE_HPP
#define EX03_ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria{
public:
	Ice();
	Ice(const Ice &other);
	Ice &operator=(const Ice & other);
	~Ice();

	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif //EX03_ICE_HPP
