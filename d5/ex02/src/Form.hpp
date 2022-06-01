//
// Created by fschlute on 5/31/22.
//

#ifndef EX01_FORM_HPP
#define EX01_FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;

class Form {
private:
	const std::string name;
	const short signGrade;
	const short executeGrade;
	bool isSigned;

	Form &operator=(const Form &);
protected:
	void guardSignature(const Bureaucrat &bureaucrat) const;
	void guardExecution(const Bureaucrat &bureaucrat) const;
public:
	Form(const std::string &name, const short signGrade, const short executeGrade);
	Form(const Form &other);
	virtual ~Form();

	const std::string &getName() const;
	short getSignGrade() const;
	short getExecuteGrade() const;
	bool getIsSigned() const;
	virtual void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(const Bureaucrat &bureaucrat) const = 0;
};

std::ostream &operator<<(std::ostream &os, const Form &form);


#endif //EX01_FORM_HPP
