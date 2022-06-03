//
// Created by fleanegan on 03.06.22.
//

#ifndef EX02_C_HPP
#define EX02_C_HPP

#include "Base.hpp"

class C : public Base{
public:
	C();
	C(const C &other);
	C &operator=(const C &);
	~C();
};

#endif //EX02_C_HPP
