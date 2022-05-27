//
// Created by fschlute on 5/27/22.
//

#ifndef EX00_CAT_HPP
#define EX00_CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
private:
	Brain *brain;
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &);
	~Cat();

	void makeSound() const override;
	void think(const std::string &idea);
};

#endif //EX00_CAT_HPP
