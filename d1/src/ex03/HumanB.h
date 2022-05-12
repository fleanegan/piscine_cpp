//
// Created by fleanegan on 11.05.22.
//

#ifndef EX03_HUMAN_B_H
#define EX03_HUMAN_B_H
#include <string>
#include <iostream>
#include <utility>
#include "Weapon.h"

class HumanB {
private:
	const std::string name;
	Weapon *weapon;
public:
	explicit HumanB(const std::string &name);
	HumanB(const HumanB& other);
	HumanB & operator = (const HumanB& other);
	~HumanB();

	void	attack(void);
	void	setWeapon(const Weapon &weapon);
};

#endif //EX03_HUMAN_B_H
