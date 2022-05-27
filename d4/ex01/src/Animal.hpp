//
// Created by fschlute on 5/27/22.
//

#ifndef EX00_ANIMAL_HPP
#define EX00_ANIMAL_HPP

#include <string>
#include <iostream>
#define override


class Animal {
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &);
	virtual ~Animal();

	virtual void makeSound() const;
	const std::string &getType() const;
};

#endif //EX00_ANIMAL_HPP
