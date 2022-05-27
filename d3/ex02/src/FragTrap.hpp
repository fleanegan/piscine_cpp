//
// Created by fschlute on 5/23/22.
//

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.h"
#define FRAG_TRAP_DEFAULT_HIT_POINTS 100
#define FRAG_TRAP_DEFAULT_ENERGY_POINTS 100
#define FRAG_TRAP_DEFAULT_ATTACK_POINTS 30

class FragTrap : virtual public ClapTrap{
private:
	void printPersonalizedConstructorMessage() const;
	void printPersonalizedDestructorMessage() const;
	void printGenericConstructorMessage() const;
protected:
	FragTrap();
public:
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &);
	~FragTrap();

	void highFivesGuys();
};

#endif //FRAG_TRAP_HPP
