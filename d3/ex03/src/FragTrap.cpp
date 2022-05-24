//
// Created by fschlute on 5/23/22.
//

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name, \
	100,\
	100, \
	30){
	printPersonalizedConstructorMessage();
}

FragTrap::FragTrap(const FragTrap &other)
	: ClapTrap(other.name, \
	other.hitPoints, \
	other.energyPoints, \
	other.attackDamage){}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	this->name = other.name;
	return *this;
}

FragTrap::~FragTrap() {
	printPersonalizedDestructorMessage();
}

void FragTrap::printPersonalizedConstructorMessage() const {
	std::cout << "FragTrap " << name << " emerged from pure unpasteurized milk" << std::endl;
}

void FragTrap::printPersonalizedDestructorMessage() const {
	std::cout << "FragTrap " << name << " has been utterly ravaged" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << name << " registered a high five request" << std::endl;
}
