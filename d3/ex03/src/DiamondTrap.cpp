#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name) \
		: ClapTrap(), FragTrap(), ScavTrap() {
	this->name = name;
	this->ClapTrap::name = name + "_clap_name";
	this->hitPoints = this->FragTrap::hitPoints;
	this->energyPoints = this->ScavTrap::energyPoints;
	this->attackDamage = this->FragTrap::attackDamage;
	printConstructorMessage(name);
}

DiamondTrap::DiamondTrap(const DiamondTrap &other){
	*this = other;
	printConstructorMessage(name);
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other){
	this->ClapTrap::operator=(other);
    return *this;
}

DiamondTrap::~DiamondTrap(){

}

void DiamondTrap::attack(const std::string& target){
    this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(){
    std::cout << "own name: " << this->name << " | trap clap name: " << this->ClapTrap::name << std::endl;
}

void DiamondTrap::beRepaired(const int &amount) {
	this->ClapTrap::beRepaired(amount);
}

void DiamondTrap::printConstructorMessage(const std::string &name) const {
	std::cout << "DiamondTrap " << name << " commenced to exist" << std::endl;
}

void DiamondTrap::printDestructorMessage(const std::string &name) const {
	std::cout << "DiamondTrap " << name << " is over and out" << std::endl;
}
