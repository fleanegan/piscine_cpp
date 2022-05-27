//
// Created by fschlute on 5/27/22.
//

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "WrongCat constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) {
	std::cout << "WrongCat copy constructor" << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << "WrongCat assignment operator" << std::endl;
	type = other.type;
	return *this;
}

WrongCat::~WrongCat() {

}

void WrongCat::makeSound() const {
	std::cout << "~bark" << std::endl;
}
