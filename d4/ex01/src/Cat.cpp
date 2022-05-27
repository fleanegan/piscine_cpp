//
// Created by fschlute on 5/27/22.
//

#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructor" << std::endl;
}

Cat::Cat(const Cat &other) {
	brain = new Brain();
	*this = other;
	std::cout << "Cat copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat assignment operator" << std::endl;
	type = other.type;
	*brain = *other.brain;
	return *this;
}

Cat::~Cat() {
	delete brain;
}

void Cat::makeSound() const {
	if (brain->getThoughtCount() == 0)
		std::cout << "~bark" << std::endl;
	else
		brain->show();
}

void Cat::think(const std::string &idea) {
	brain->addIdea(idea);
}