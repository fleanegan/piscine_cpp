//
// Created by fleanegan on 03.06.22.
//

#ifndef EX02_B_HPP
#define EX02_B_HPP

#include "Base.hpp"

class B : public Base{
public:
	B();
	B(const B &other);
	B &operator=(const B &);
	~B();
};

#endif //EX02_B_HPP
