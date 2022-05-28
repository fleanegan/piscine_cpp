#ifndef TESTING

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void createAnimalArray(int animalCount, Animal **arr);
void deleteAnimalArray(int animalCount, Animal *const *arr);

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
	std::cout << "_________________________________" << std::endl;
	std::cout << "a has something to say:" << std::endl;
	Dog a = getTestDog();
	a.makeSound();
	std::cout << " a is of type " << a.getType() << std::endl;
	std::cout << "_________________________________" << std::endl;
	std::cout << "b has something to say:" << std::endl;
	Cat b = getTestCat();
	b.makeSound();
	std::cout << " b is of type " << b.getType() << std::endl;
	std::cout << "_________________________________" << std::endl;
	std::cout << "c gets constructed from b. Is it a deep copy?" << std::endl;
	Cat c = b;
	c.think("I am different.");
	std::cout << "b says:" << std::endl;
	b.makeSound();
	std::cout << "c says:" << std::endl;
	c.makeSound();
	std::cout << "_________________________________" << std::endl;
	std::cout << "mixed array" << std::endl;
	int	animalCount = 5;
	Animal *arr[animalCount];
	createAnimalArray(animalCount, arr);
	deleteAnimalArray(animalCount, arr);
	return 0;
}

void deleteAnimalArray(int animalCount, Animal *const *arr) {
	for (int i = 0; i < animalCount; ++i) {
		delete arr[i];
	}
}

void createAnimalArray(int animalCount, Animal **arr) {
	for (int i = 0; i < animalCount; ++i) {
		if (i < animalCount / 2)
			arr[i] = new Cat;
		else
			arr[i] = new Dog;
	}
	//this would be illegal
	//Animal a;
}

#endif
