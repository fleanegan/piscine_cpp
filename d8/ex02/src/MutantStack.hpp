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
	typedef typename std::deque<T>::const_iterator const_iterator;
	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
	typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;
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

	const_iterator cbegin() {
		return this->c.cbegin();
	}

	const_iterator cend() {
		return this->c.cend();
	}

	reverse_iterator rbegin() {
		return this->c.rbegin();
	}

	reverse_iterator rend() {
		return this->c.rend();
	}

	const_reverse_iterator crbegin() {
		return this->c.crbegin();
	}

	const_reverse_iterator crend() {
		return this->c.crend();
	}
};

#endif //EX02_MUTANTSTACK_HPP
