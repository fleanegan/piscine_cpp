#ifndef TESTING

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void ) {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	std::cout << "var i is of type: " << i->getType() << std::endl;
	j->makeSound();
	std::cout << "var j is of type: " << j->getType() << std::endl;
	meta->makeSound();
	Animal *p = new Cat();
	Animal *q = new Dog();
	delete p;
	p = q;
	p->makeSound();
	delete p;
	std::cout << "'''''''''''''''''''''''WrongAnimal'''''''''''''''''''''''" << std::endl;
	WrongAnimal a = WrongCat();
	a.makeSound();

	delete meta;
	delete i;
	delete j;
	return 0;
}

#endif
