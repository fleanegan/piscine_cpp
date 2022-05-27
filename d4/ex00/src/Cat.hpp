//
// Created by fschlute on 5/27/22.
//

#ifndef EX00_CAT_HPP
#define EX00_CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &);
	~Cat();

	void makeSound() const override;
};

#endif //EX00_CAT_HPP
