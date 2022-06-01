//
// Created by fschlute on 5/31/22.
//

#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, short initGrade) :\
		name(name), grade(initGrade){
	std::cout << "Bureaucrat constructor, init grade: " << initGrade << ", name: " << name << std::endl;
	if (initGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (initGrade > MIN_GRADE)
		throw GradeTooLowException();
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

void Bureaucrat::incrementGrade() {
	if (grade == MAX_GRADE)
		throw GradeTooHighException();
	--grade;
}

void Bureaucrat::decrementGrade() {
	if (grade == MIN_GRADE)
		throw GradeTooLowException();
	++grade;
}

bool Bureaucrat::signForm(Form &form) {
	try{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
		return true;
	}
	catch (const std::exception &e){
		std::cout << name << " couldn't sign " << form.getName() << "because this is not our responsibility" << std::endl;
		return false;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
