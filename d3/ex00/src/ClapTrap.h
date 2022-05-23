//
// Created by fschlute on 5/23/22.
//

#ifndef EX00_CLAPTRAP_H
#define EX00_CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap {
protected:
	std::string		name;
	unsigned int	hitPoints;
	unsigned int	energyPoints;
	unsigned int	attackDamage;
public:
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void printConstructorMessage() const;
	void printDestructorMessage() const;
	void printUnsuccessfullAttackMessage() const;
	void printSuccessfullAttackMessage(const std::string &target) const;
	void printDamageMessage(unsigned int amount) const;
	void printUnsuccessfulRepairMessage() const;
	void printSuccessfulRepairMessage(unsigned int amount) const;
};


#endif //EX00_CLAPTRAP_H
