//
// Created by fleanegan on 28.05.22.
//

#ifndef EX03_CHARACTER_HPP
#define EX03_CHARACTER_HPP

#define INVENTORY_MAX 4

#include "ICharacter.hpp"

class Character : public ICharacter {
private:
	std::string name;
	AMateria *inventory[INVENTORY_MAX];

	void emptyInventory();
public:
	explicit Character(const std::string &name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	virtual ~Character();
	virtual const std::string &getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);
	bool isIndexValid(int idx) const;
};

#endif //EX03_CHARACTER_HPP
