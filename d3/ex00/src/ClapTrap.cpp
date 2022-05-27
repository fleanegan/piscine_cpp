//
// Created by fschlute on 5/23/22.
//

#include "ClapTrap.h"

ClapTrap::ClapTrap() : \
		isBaseClass(true), \
		name(""), \
		hitPoints(CLAP_TRAP_DEFAULT_HIT_POINTS), \
		energyPoints(CLAP_TRAP_DEFAULT_ENERGY_POINTS), \
		attackDamage(CLAP_TRAP_DEFAULT_ATTACK_POINTS) {
	printGenericConstructorMessage();
}

ClapTrap::ClapTrap(const std::string &name) : \
		isBaseClass(false), \
		name(name), \
		hitPoints(CLAP_TRAP_DEFAULT_HIT_POINTS), \
		energyPoints(CLAP_TRAP_DEFAULT_ENERGY_POINTS), \
		attackDamage(CLAP_TRAP_DEFAULT_ATTACK_POINTS){
	printPersonalizedConstructorMessage();
}

ClapTrap::ClapTrap(const std::string &name, const int &hitPoints, const int &energyPoints, const int &attackDamage) : \
		isBaseClass(true), \
		name(name), \
		hitPoints(hitPoints), \
		energyPoints(energyPoints), \
		attackDamage(attackDamage){
	printGenericConstructorMessage();
}

ClapTrap::ClapTrap(const ClapTrap &other){
	*this = other;
	if (isBaseClass)
		printGenericConstructorMessage();
	else
		printPersonalizedConstructorMessage();
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
	isBaseClass = other.isBaseClass;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
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
	if (amount < hitPoints)
		hitPoints -= amount;
	else
		hitPoints = 0;
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
	std::cout << "oi mate! cannot repair stuff without energy and hit points left. buy some kong strong" << std::endl;
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

const std::string &ClapTrap::getName() const {
	return name;
}

void ClapTrap::setName(const std::string &name) {
	this->name = name;
}

unsigned int ClapTrap::getHitPoints() const {
	return hitPoints;
}

void ClapTrap::setHitPoints(unsigned int hitPoints) {
	this->hitPoints = hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
	return energyPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
	this->energyPoints = energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
	return attackDamage;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
	this->attackDamage = attackDamage;
}

