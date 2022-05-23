//
// Created by fschlute on 5/23/22.
//

#include "ClapTrap.h"


ClapTrap::ClapTrap(std::string &name) : name(name), hitPoints(10), energyPoints(10), attacDamage(0){

}

ClapTrap::ClapTrap(const ClapTrap &other) {
	(void) other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
	return (*this);
}

ClapTrap::~ClapTrap() {

}

void ClapTrap::attack(const std::string &target) {

}

void ClapTrap::takeDamage(unsigned int amount) {

}

void ClapTrap::beRepaired(unsigned int amount) {

}
