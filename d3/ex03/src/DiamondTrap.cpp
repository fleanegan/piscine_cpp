#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name+"_clap_name", 100, 50, 30),ScavTrap(name), FragTrap(name),  name(name){}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.name+"_clap_name", 100, 50, 30),ScavTrap(other.name), FragTrap(other.name),  name(other.name){

}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other){
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    this->name = other.name;
    return *this;
}

DiamondTrap::~DiamondTrap(){}

void DiamondTrap::attack(const std::string& target){
    this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(){
    std::cout << "own name: " << this->name << " | trap clap name: " << this->ClapTrap::name << std::endl;
}