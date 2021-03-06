//
// Created by fleanegan on 28.05.22.
//

#ifndef EX03_CHARACTER_HPP
#define EX03_CHARACTER_HPP

#include "ICharacter.hpp"
#include "Inventory.hpp"

class Character : public ICharacter {
private:
	std::string name;
	Inventory inventory;
public:
	explicit Character(const std::string &name);
	Character(Character &other);
	Character &operator=(Character &other);
	virtual ~Character();
	virtual const std::string &getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);
};

#endif //EX03_CHARACTER_HPP
