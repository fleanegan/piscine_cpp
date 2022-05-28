//
// Created by fschlute on 5/27/22.
//

#ifndef EX00_ANIMAL_HPP
#define EX00_ANIMAL_HPP

#include <string>
#include <iostream>
#define override
#define DEBUG_FLAG 0

class Animal {
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &);
	virtual ~Animal();

	virtual void makeSound() const = 0;
	const std::string &getType() const;
};

#endif //EX00_ANIMAL_HPP
