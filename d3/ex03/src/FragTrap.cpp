//
// Created by fschlute on 5/23/22.
//

#include "FragTrap.hpp"

FragTrap::FragTrap() : \
	ClapTrap(){
	this->hitPoints = FRAG_TRAP_DEFAULT_HIT_POINTS;
	this->energyPoints = FRAG_TRAP_DEFAULT_ENERGY_POINTS;
	this->attackDamage = FRAG_TRAP_DEFAULT_ATTACK_POINTS;
	printGenericConstructorMessage();
}

FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name, \
	FRAG_TRAP_DEFAULT_HIT_POINTS,\
	FRAG_TRAP_DEFAULT_ENERGY_POINTS, \
	FRAG_TRAP_DEFAULT_ATTACK_POINTS){
	printPersonalizedConstructorMessage();
}

FragTrap::FragTrap(const FragTrap &other){
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap() {
	printPersonalizedDestructorMessage();
}

void FragTrap::printPersonalizedConstructorMessage() const {
	std::cout << "FragTrap " << this->ClapTrap::name << " emerged from pure unpasteurized milk" << std::endl;
}

void FragTrap::printGenericConstructorMessage() const {
	std::cout << "FragTrap is used as a base class" << std::endl;
}

void FragTrap::printPersonalizedDestructorMessage() const {
	std::cout << "FragTrap " << this->ClapTrap::name << " has been utterly ravaged" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->ClapTrap::name << " registered a high five request" << std::endl;
}
