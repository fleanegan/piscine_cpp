//
// Created by fschlute on 5/31/22.
//

#include "Form.hpp"

Form::Form(const std::string &name, const short signGrade, const short executeGrade) :\
		name(name),
		signGrade(signGrade),
		executeGrade(executeGrade),
		isSigned(false){
	std::cout << "Form constructor" << std::endl;
	if (signGrade > MIN_GRADE || executeGrade > MIN_GRADE)
		throw GradeTooLowException();
	if (signGrade < MAX_GRADE || executeGrade < MAX_GRADE)
		throw GradeTooHighException();
}

Form::Form(const Form &other) :\
		name (other.name),
		signGrade(other.signGrade),
		executeGrade(other.executeGrade),
		isSigned(other.isSigned){
	std::cout << "Form copy constructor" << std::endl;
}

Form &Form::operator=(const Form &other) {
	std::cout << "Form assignment" << std::endl;
	isSigned = other.isSigned;
	return (*this);
}

Form::~Form() {
	std::cout << "Form destructor" << std::endl;
}

const std::string &Form::getName() const {
	return name;
}

short Form::getSignGrade() const {
	return signGrade;
}

short Form::getExecuteGrade() const {
	return executeGrade;
}

bool Form::getIsSigned() const {
	return isSigned;
}

bool Form::beSigned(const Bureaucrat &bureaucrat) const {
	if (bureaucrat.getGrade() > signGrade)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << name << " because he is not responsible for this kind of problems";
		return false;
	}
	std::cout << bureaucrat.getName() << " signed " << name;
	return true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "name: " << form.getName() \
	<< " signGrade: " << form.getSignGrade() \
	<< " executeGrade: " << form.getExecuteGrade() \
	<< " isSigned: " << form.getIsSigned();
	return os;
}
