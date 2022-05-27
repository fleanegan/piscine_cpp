//
// Created by fschlute on 5/23/22.
//

#ifndef EX00_CLAPTRAP_H
#define EX00_CLAPTRAP_H
#include <string>
#include <iostream>

#define override
#define CLAP_TRAP_DEFAULT_HIT_POINTS 10
#define CLAP_TRAP_DEFAULT_ENERGY_POINTS 10
#define CLAP_TRAP_DEFAULT_ATTACK_POINTS 0

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
public:
	const std::string &getName() const;
	void setName(const std::string &name);
	unsigned int getHitPoints() const;
	void setHitPoints(unsigned int hitPoints);
	unsigned int getEnergyPoints() const;
	void setEnergyPoints(unsigned int energyPoints);
	unsigned int getAttackDamage() const;
	void setAttackDamage(unsigned int attackDamage);
protected:
	unsigned int	hitPoints;
	unsigned int	energyPoints;
	unsigned int	attackDamage;

	ClapTrap(const std::string &name, const int &hitPoints, const int &energyPoints, const int &attackDamage);
	ClapTrap();
	virtual void printUnsuccessfullAttackMessage() const;
	virtual void printSuccessfullAttackMessage(const std::string &target) const;
public:
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &);
	~ClapTrap();

	virtual void	attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			printGenericDestructorMessage();
};


#endif //EX00_CLAPTRAP_H
