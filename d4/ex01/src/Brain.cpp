//
// Created by fschlute on 5/27/22.
//

#include "Brain.hpp"

Brain::Brain() : i(0){
	std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain assignment operator" << std::endl;
	for (int i = 0; i < IDEA_MAX_COUNT; ++i) {
		this->ideas[i] = other.ideas[i];
	}
	i = other.i;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor" << std::endl;
}

void Brain::addIdea(const std::string &idea) {
	if (i < IDEA_MAX_COUNT)
	{
		ideas[i] = idea;
		i++;
	}
}

int Brain::getThoughtCount() const {
	return i;
}

void Brain::show() const {
	for (int j = 0; j < i; ++j) {
		std::cout << ideas[j] << std::endl;
	}
}
