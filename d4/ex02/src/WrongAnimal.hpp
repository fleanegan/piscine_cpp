//
// Created by fschlute on 5/27/22.
//

#ifndef EX00_WRONG_ANIMAL_HPP
#define EX00_WRONG_ANIMAL_HPP

#include <string>
#include <iostream>
#define override


class WrongAnimal {
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &);
	virtual ~WrongAnimal();

	void makeSound() const;
	const std::string &getType() const;
};

#endif //EX00_WRONG_ANIMAL_HPP
