//
// Created by fleanegan on 11.05.22.
//


#include "HumanB.h"

void HumanB::setWeapon(const Weapon &weapon) {
	this->weapon = const_cast<Weapon *>(&weapon);
}

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL){
}

HumanB::HumanB(const HumanB &other) : name(other.name), weapon(other.weapon){
}

HumanB &HumanB::operator=(const HumanB &other) {
	return *this;
	(void) other;
}

HumanB::~HumanB() {

}

void HumanB::attack(void) {
	if (weapon == NULL)
		std::cout << name << " attacks with their bare hands" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
