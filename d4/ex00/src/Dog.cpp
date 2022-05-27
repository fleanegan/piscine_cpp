//
// Created by fschlute on 5/27/22.
//

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &other) {
	std::cout << "Dog copy constructor" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog assignment operator" << std::endl;
	type = other.type;
	return *this;
}

Dog::~Dog() {
}

void Dog::makeSound() const {
	std::cout << "bark" << std::endl;
}
