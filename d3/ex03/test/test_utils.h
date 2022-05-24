#ifndef TEST_UTILS_H
# define TEST_UTILS_H

#include "gtest/gtest.h"
#include "../src/ClapTrap.h"
#include "../src/ScavTrap.hpp"
#include "../src/FragTrap.hpp"
#include <iostream>


struct ClapTrapTester : public ClapTrap{

	ClapTrapTester(const std::string & name) : ClapTrap(name){}

	int getHitPoints() const{
		return this->hitPoints;
	}
	int getEnergyPoints() const{
		return this->energyPoints;
	}
	int getAttackDamage() const{
		return this->attackDamage;
	}
	void setEnergyPoints(const int & in){
		this->energyPoints = in;
	}

protected:
	void printUnsuccessfullAttackMessage() const override {}
	void printSuccessfullAttackMessage(const std::string &target) const override {}
	void printDamageMessage(unsigned int amount) const override {}
	void printUnsuccessfulRepairMessage() const override {}
	void printSuccessfulRepairMessage(unsigned int amount) const override {}
private:
	void printPersonalizedConstructorMessage() const {}
	void printPersonalizedDestructorMessage() const {}
};

struct ScavTrapTester : public ScavTrap {
	ScavTrapTester(const std::string & name) : ScavTrap(name), ClapTrap(name, 100, 50, 20){}

	int getHitPoints() const{
		return this->hitPoints;
	}
	int getEnergyPoints() const{
		return this->energyPoints;
	}
	int getAttackDamage() const{
		return this->attackDamage;
	}
	void setEnergyPoints(const int & in){
		this->energyPoints = in;
	}
protected:
	void printUnsuccessfullAttackMessage() const override {}
	void printSuccessfullAttackMessage(const std::string &target) const override {}
	void printDamageMessage(unsigned int amount) const override {}
	void printUnsuccessfulRepairMessage() const override {}
	void printSuccessfulRepairMessage(unsigned int amount) const override {}
private:
	void printPersonalizedConstructorMessage() const {}
	void printPersonalizedDestructorMessage() const {}
};

struct FragTrapTester : public FragTrap {
	FragTrapTester(const std::string & name) : FragTrap(name), ClapTrap(name, 100, 100, 30){}

	int getHitPoints() const{
		return this->hitPoints;
	}
	int getEnergyPoints() const{
		return this->energyPoints;
	}
	int getAttackDamage() const{
		return this->attackDamage;
	}
	void setEnergyPoints(const int & in){
		this->energyPoints = in;
	}
protected:
	void printUnsuccessfullAttackMessage() const override {}
	void printSuccessfullAttackMessage(const std::string &target) const override {}
	void printDamageMessage(unsigned int amount) const override {}
	void printUnsuccessfulRepairMessage() const override {}
	void printSuccessfulRepairMessage(unsigned int amount) const override {}
private:
	void printPersonalizedConstructorMessage() const {}
	void printPersonalizedDestructorMessage() const {}
};


#endif	 // TEST_UTILS_H
