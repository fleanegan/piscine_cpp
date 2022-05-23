//
// Created by fschlute on 5/23/22.
//

#ifndef EX00_CLAPTRAP_H
#define EX00_CLAPTRAP_H

#include <string>

class ClapTrap {
private:
	int			hitPoints;
	int			energyPoints;
	int			attacDamage;
	std::string name;
public:
	ClapTrap(std::string &name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};


#endif //EX00_CLAPTRAP_H
