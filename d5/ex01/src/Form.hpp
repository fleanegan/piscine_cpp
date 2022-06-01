//
// Created by fschlute on 5/31/22.
//

#ifndef EX01_FORM_HPP
#define EX01_FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Form {
private:
	const std::string name;
	const short signGrade;
	const short executeGrade;
	bool isSigned;
	
	Form &operator=(const Form &);
public:
	Form(const std::string &name, const short signGrade, const short executeGrade);
	Form(const Form &other);
	~Form();

	const std::string &getName() const;
	short getSignGrade() const;
	short getExecuteGrade() const;
	bool getIsSigned() const;
	bool beSigned(const Bureaucrat &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &os, const Form &form);


#endif //EX01_FORM_HPP
