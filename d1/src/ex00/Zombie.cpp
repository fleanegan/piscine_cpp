//
// Created by fleanegan on 11.05.22.
//


#include "Zombie.h"

Zombie::Zombie(std::string name) : name(name){
	announce();
}

void	Zombie::announce(void){
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(const Zombie &other) {
	name = other.name;
}

Zombie &Zombie::operator=(const Zombie &other) {
	name = other.name;
	return *this;
}

Zombie::~Zombie() {
	std::cout << name << " is cleared" << std::endl;
}
