//
// Created by fschlute on 5/27/22.
//

#include "Animal.hpp"

Animal::Animal() {
	DEBUG_FLAG && std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(const Animal &other) {
	*this = other;
	DEBUG_FLAG && std::cout << "Animal copy constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	type = other.type;
	DEBUG_FLAG && std::cout << "Animal assignment operator" << std::endl;
	return *this;
}

Animal::~Animal() {
	DEBUG_FLAG && std::cout << "Animal destructor" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Generic animal sound" << std::endl;
}

const std::string &Animal::getType() const {
	return type;
}
