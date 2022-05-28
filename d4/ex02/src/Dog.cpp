//
// Created by fschlute on 5/27/22.
//

#include "Dog.hpp"

Dog::Dog() {
	brain = new Brain();
	DEBUG_FLAG && std::cout << "Dog constructor" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other) {
	DEBUG_FLAG && std::cout << "Dog copy constructor" << std::endl;
	brain = new Brain();
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	DEBUG_FLAG && std::cout << "Dog assignment operator" << std::endl;
	*brain = *other.brain;
	type = other.type;
	return *this;
}

Dog::~Dog() {
	delete brain;
}

void Dog::makeSound() const {
	if (brain->getThoughtCount() == 0)
		std::cout << "bark" << std::endl;
	else
		brain->show();
}

void Dog::think(const std::string &idea) {
	brain->addIdea(idea);
}
