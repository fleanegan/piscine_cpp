#ifndef TESTING

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

Dog getTestDog(){
	Dog a;
	a.think("Maroilles");
	a.think("Cantal");
	Dog b(a);
	Dog c;
	c = b;
	return c;
}

Cat getTestCat(){
	Cat a;
	a.think("J'aime la tartiflette");
	a.think("Le gout du fromage me rappelle mon enfance");
	Cat b(a);
	Cat c;
	c = b;
	return c;
}

int main( void ) {
//	const Animal* meta = new Animal();
//	const Animal* j = new Dog();
//	const Animal* i = new Cat();
//	std::cout << j->getType() << " " << std::endl;
//	std::cout << i->getType() << " " << std::endl;
//	i->makeSound();
//	std::cout << "var i is of type: " << i->getType() << std::endl;
//	j->makeSound();
//	std::cout << "var j is of type: " << j->getType() << std::endl;
//	meta->makeSound();
//	delete meta;
//	delete i;
//	delete j;
	Dog a = getTestDog();
	a.makeSound();
	Cat b = getTestCat();
	b.makeSound();
//	Cat b = getTestCat();
	return 0;
}

#endif
