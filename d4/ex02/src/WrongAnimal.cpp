//
// Created by fschlute on 5/27/22.
//

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	*this = other;
	std::cout << "WrongAnimal copy constructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	type = other.type;
	std::cout << "WrongAnimal assignment operator" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "Generic animal sound" << std::endl;
}

const std::string &WrongAnimal::getType() const {
	return type;
}
