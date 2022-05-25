//
// Created by fschlute on 5/23/22.
//

#include "ClapTrap.h"


ClapTrap::ClapTrap(const std::string &name) : isBaseClass(false), name(name), hitPoints(10), energyPoints(10), attackDamage(0){
	printPersonalizedConstructorMessage();
}

ClapTrap::ClapTrap(const std::string &name, const int &hitPoints, const int &energyPoints, const int &attackDamage)
		: isBaseClass(true), name(name), hitPoints(hitPoints), energyPoints(energyPoints), attackDamage(attackDamage){
	printGenericConstructorMessage();
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	(void) other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
	(void) other;
	return (*this);
}

ClapTrap::~ClapTrap() {
	if (isBaseClass)
		printGenericDestructorMessage();
	else
		printPersonalizedDestructorMessage();

}

void ClapTrap::attack(const std::string &target) {
	if (energyPoints == 0 || hitPoints <= 0)
	{
		printUnsuccessfullAttackMessage();
		return ;
	}
	energyPoints--;
	printSuccessfullAttackMessage(target);
	(void) target;
}

void ClapTrap::takeDamage(unsigned int amount) {
	printDamageMessage(amount);
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints == 0 || hitPoints <= 0)
	{
		printUnsuccessfulRepairMessage();
		return ;
	}
	hitPoints += amount;
	energyPoints--;
	printSuccessfulRepairMessage(amount);
	(void) amount;
}

void ClapTrap::printSuccessfulRepairMessage(unsigned int amount) const {
	std::cout << "ClapTrap " << name << " got repaired by " << amount << " hitpoints, causing a total of " << hitPoints << " !" << std::endl;
}

void ClapTrap::printUnsuccessfulRepairMessage() const {
	std::cout << "oi mate! cannot repair stuff without energy left. buy some kong strong" << std::endl;
}

void ClapTrap::printPersonalizedConstructorMessage() const {
	std::cout << "ClapTrap " << name << " is born. Admit you greedily looked at the frigo" << std::endl;
}

void ClapTrap::printPersonalizedDestructorMessage() const {
	std::cout << "ClapTrap " << name << " has given its last bit. " << std::endl;
}

void ClapTrap::printSuccessfullAttackMessage(const std::string &target) const {
	std::cout << "ClapTrap " << name << " attacks " << target << " , causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::printUnsuccessfullAttackMessage() const {
	std::cout << "oi mate! cannot attack without energy left. buy some kong strong" << std::endl;
}

void ClapTrap::printDamageMessage(unsigned int amount) const {
	std::cout << "ClapTrap " << name << " was attacked taking " << amount << " points of damage!" << std::endl;
}

void ClapTrap::printGenericConstructorMessage() const {
	std::cout << "ClapTrap is constructed as base class" << std::endl;
}

void ClapTrap::printGenericDestructorMessage() {
	std::cout << "ClapTrap was used as base class and is now destroyed" << std::endl;

}

