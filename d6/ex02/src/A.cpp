//
// Created by fleanegan on 03.06.22.
//

#include "A.hpp"

A::A() {

}

A::A(const A &other) {
	(void) other;
}

A &A::operator=(const A &other) {
	(void) other;
	return *this;
}

A::~A() {

}
