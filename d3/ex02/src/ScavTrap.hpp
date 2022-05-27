//
// Created by fschlute on 5/23/22.
//

#ifndef EX01_SCAVTRAP_HPP
#define EX01_SCAVTRAP_HPP

#include "ClapTrap.h"
#define SCAV_TRAP_DEFAULT_HIT_POINTS 100
#define SCAV_TRAP_DEFAULT_ENERGY_POINTS 50
#define SCAV_TRAP_DEFAULT_ATTACK_POINTS 20

class ScavTrap : virtual public ClapTrap{
private:
	void printPersonalizedConstructorMessage() const;
	void printGenericConstructorMessage() const;
protected:
	ScavTrap();
	void printUnsuccessfullAttackMessage() const override;
	void printSuccessfullAttackMessage(const std::string &target) const override;
	void printPersonalizedDestructorMessage() const override;
public:
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &);
	~ScavTrap();

	void guardGate();
};

#endif //EX01_SCAVTRAP_HPP
