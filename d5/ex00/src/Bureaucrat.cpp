//
// Created by fschlute on 5/31/22.
//

#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, short initGrade) :\
		name(name), grade(initGrade){
	std::cout << "Bureaucrat constructor, init grade: " << initGrade << ", name: " << name << std::endl;
	if (initGrade > MAX_GRADE)
		throw GradeTooLowException();
	if (initGrade < MIN_GRADE)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :\
		name(other.name), grade(other.grade){
	std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat assignment" << std::endl;
	if (this == &other)
		return *this;
	grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor" << std::endl;
}

std::string Bureaucrat::getName() const{
	return name;
}

short Bureaucrat::getGrade() const {
	return grade;
}
