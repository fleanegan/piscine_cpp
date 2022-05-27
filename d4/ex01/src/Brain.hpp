	//
// Created by fschlute on 5/27/22.
//

#ifndef EX01_BRAIN_HPP
#define EX01_BRAIN_HPP
#define IDEA_MAX_COUNT 100

#include <iostream>
#include <string>

class Brain {
private:
	std::string ideas[IDEA_MAX_COUNT];
	int i;
public:
	int getThoughtCount() const;
public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &);
	~Brain();

	void show() const;
	void addIdea(const std::string &idea);
};

#endif //EX01_BRAIN_HPP
