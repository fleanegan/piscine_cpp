//
// Created by fschlute on 5/23/22.
//

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : \
	ClapTrap(){
	this->hitPoints = SCAV_TRAP_DEFAULT_HIT_POINTS;
	this->energyPoints = SCAV_TRAP_DEFAULT_ENERGY_POINTS;
	this->attackDamage = SCAV_TRAP_DEFAULT_ATTACK_POINTS;
	printGenericConstructorMessage();
}

ScavTrap::ScavTrap(const std::string &name)
		: ClapTrap(name, \
	SCAV_TRAP_DEFAULT_HIT_POINTS,\
	SCAV_TRAP_DEFAULT_ENERGY_POINTS, \
	SCAV_TRAP_DEFAULT_ATTACK_POINTS){
	printPersonalizedConstructorMessage();
}

ScavTrap::ScavTrap(const ScavTrap &other){
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap() {
	printPersonalizedDestructorMessage();
}

void ScavTrap::printPersonalizedConstructorMessage() const {
	std::cout << "ScavTrap " << this->ClapTrap::name << " is born and looks tremendously aromatic" << std::endl;
}

void ScavTrap::printGenericConstructorMessage() const {
	std::cout << "ScavTrap is used as a base class" << std::endl;
}

void ScavTrap::printPersonalizedDestructorMessage() const {
	std::cout << "ScavTrap " << this->ClapTrap::name << " is done" << std::endl;
}

void ScavTrap::printUnsuccessfullAttackMessage() const {
	std::cout << "ScavTrap " << this->ClapTrap::name << " cannot attack since there is no energy left." << std::endl;
}

void ScavTrap::printSuccessfullAttackMessage(const std::string &target) const {
	std::cout << "ScavTrap " << this->ClapTrap::name << " is fiercely attacking " << target << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->ClapTrap::name << " is now in Gate keeper mode" << std::endl;
}
