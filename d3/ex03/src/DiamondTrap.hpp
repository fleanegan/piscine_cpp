#ifndef DIAMOND_TRAP_H
#define DIAMOND_TRAP_H
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : protected ScavTrap, protected FragTrap{
private:
	std::string name;
public:
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &other);
	~DiamondTrap();

	void attack(const std::string& target);
	void whoAmI();
	void beRepaired(const int &amount);
};




#endif
