//
// Created by fleanegan on 08.06.22.
//

#ifndef EX02_MUTANTSTACK_HPP
#define EX02_MUTANTSTACK_HPP

#include <stack>
#include <clocale>

template <typename T>
class MutantStack : public std::stack<T>{
public:
	typedef typename std::deque<T>::iterator iterator;
	MutantStack() : std::stack<T>() {

	}

	MutantStack(const MutantStack &other) {
		*this = other;
	}

	MutantStack &operator=(const MutantStack &other) {
		if (this == &other)
			return *this;
		//this->std::stack = other.std::stack;
		return *this;
	}

	~MutantStack() {

	}

	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}
};

#endif //EX02_MUTANTSTACK_HPP
