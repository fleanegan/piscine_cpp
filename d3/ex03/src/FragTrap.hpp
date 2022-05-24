//
// Created by fschlute on 5/23/22.
//

#ifndef EX01_FRAGTRAP_HPP
#define EX01_FRAGTRAP_HPP

#include "ClapTrap.h"

class FragTrap : virtual public ClapTrap{
private:
	void printPersonalizedConstructorMessage() const;
	void printPersonalizedDestructorMessage() const;
public:
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &);
	~FragTrap();

	void highFivesGuys();
};

#endif //EX01_FRAGTRAP_HPP
