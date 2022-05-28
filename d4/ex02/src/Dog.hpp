//
// Created by fschlute on 5/27/22.
//

#ifndef EX00_DOG_HPP
#define EX00_DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
private:
	Brain *brain;
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &);
	~Dog();

	void makeSound() const override;
	void think(const std::string &idea);
};

#endif //EX00_DOG_HPP
