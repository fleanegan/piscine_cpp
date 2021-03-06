//
// Created by fschlute on 5/27/22.
//

#ifndef EX00_WRONG_CAT_HPP
#define EX00_WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
public:
	WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &);
	~WrongCat();

	void makeSound() const;
};

#endif //EX00_WRONG_CAT_HPP
