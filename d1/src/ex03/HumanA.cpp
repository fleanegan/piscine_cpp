//
// Created by fleanegan on 12.05.22.
//

#include "HumanA.h"

HumanA::HumanA(const std::string &name, const Weapon &weapon) : HumanB(name) {
	this->setWeapon(weapon);
}

HumanA::HumanA(const HumanB &other) : HumanB(other) {}

HumanA::~HumanA() {

}

HumanA &HumanA::operator=(const HumanB &other) {
	return static_cast<HumanA &>(HumanB::operator=(other));
}
