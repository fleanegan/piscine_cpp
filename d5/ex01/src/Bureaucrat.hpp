//
// Created by fschlute on 5/31/22.
//

#ifndef EX00_BUREAUCRAT_HPP
#define EX00_BUREAUCRAT_HPP

#define MAX_GRADE 1
#define MIN_GRADE 150

#include <string>
#include <ostream>
#include "CustomExceptions.hpp"
#include "Form.hpp"

class Form;

class Bureaucrat {
private:
	const std::string name;
	short grade;
	Bureaucrat &operator=(const Bureaucrat &);
public:
	Bureaucrat(const std::string &name, short initGrade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();

	void decrementGrade();
	void incrementGrade();
	std::string getName() const;
	short getGrade() const;
	bool signForm(Form &form);
};
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);


#endif //EX00_BUREAUCRAT_HPP
