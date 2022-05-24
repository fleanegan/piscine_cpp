//
// Created by fschlute on 5/23/22.
//

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name)
	: ClapTrap(name, \
	100,\
	50, \
	20){
	printPersonalizedConstructorMessage();
}

ScavTrap::ScavTrap(const ScavTrap &other)
	: ClapTrap(other.name, \
	other.hitPoints, \
	other.energyPoints, \
	other.attackDamage){}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	this->name = other.name;
	return *this;
}

ScavTrap::~ScavTrap() {
	printPersonalizedDestructorMessage();
}

void ScavTrap::printPersonalizedConstructorMessage() const {
	std::cout << "ScavTrap " << name << " is born and looks tremendously aromatic" << std::endl;
}

void ScavTrap::printPersonalizedDestructorMessage() const {
	std::cout << "ScavTrap " << name << " is done" << std::endl;
}

void ScavTrap::printUnsuccessfullAttackMessage() const {
	std::cout << "ScavTrap " << name << " cannot attack since there is no energy left." << std::endl;
}

void ScavTrap::printSuccessfullAttackMessage(const std::string &target) const {
	std::cout << "ScavTrap " << name << " is fiercely attacking " << target << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
