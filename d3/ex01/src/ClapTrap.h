//
// Created by fschlute on 5/23/22.
//

#ifndef EX00_CLAPTRAP_H
#define EX00_CLAPTRAP_H
#define override

#include <string>
#include <iostream>

class ClapTrap {
private:
	bool isBaseClass;

	void printPersonalizedConstructorMessage() const;
	void printGenericConstructorMessage() const;
	void printPersonalizedDestructorMessage() const;
	void printDamageMessage(unsigned int amount) const;
	void printUnsuccessfulRepairMessage() const;
	void printSuccessfulRepairMessage(unsigned int amount) const;
protected:
	std::string		name;
	unsigned int	hitPoints;
	unsigned int	energyPoints;
	unsigned int	attackDamage;

	ClapTrap(const std::string &name, const int &hitPoints, const int &energyPoints, const int &attackDamage);
	virtual void printUnsuccessfullAttackMessage() const;
	virtual void printSuccessfullAttackMessage(const std::string &target) const;
public:
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void printGenericDestructorMessage();
};


#endif //EX00_CLAPTRAP_H
