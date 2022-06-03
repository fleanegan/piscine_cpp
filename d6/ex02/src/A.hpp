//
// Created by fleanegan on 03.06.22.
//

#ifndef EX02_A_HPP
#define EX02_A_HPP

#include "Base.hpp"

class A : public Base{
public:
	A();
	A(const A &other);
	A &operator=(const A &);
	~A();
};

#endif //EX02_A_HPP
