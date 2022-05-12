//
// Created by fleanegan on 12.05.22.
//

#include "Weapon.h"

Weapon::Weapon(std::string type) : type(std::move(type)){
}

Weapon::Weapon(const Weapon &other) {
	(void) other;
}

Weapon &Weapon::operator=(const Weapon &other) {
	return *this;
	(void) other;
}

const std::string &Weapon::getType() const {
	return type;
}

void Weapon::setType(const std::string &type) {
	this->type = type;
}

Weapon::~Weapon() {

}
