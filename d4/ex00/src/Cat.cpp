//
// Created by fschlute on 5/27/22.
//

#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat constructor" << std::endl;
}

Cat::Cat(const Cat &other) {
	std::cout << "Cat copy constructor" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat assignment operator" << std::endl;
	type = other.type;
	return *this;
}

Cat::~Cat() {

}

void Cat::makeSound() const {
	std::cout << "I like moutarde with my Cantal" << std::endl;
}
