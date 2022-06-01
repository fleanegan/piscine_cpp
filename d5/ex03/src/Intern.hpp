//
// Created by fschlute on 6/1/22.
//

#ifndef EX03_INTERN_HPP
#define EX03_INTERN_HPP

#include "ShrubberyCreationForm.hpp"

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern {
public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &);
	~Intern();

	Form * makeForm(const std::string &formName, const std::string &target) const;
};

#endif //EX03_INTERN_HPP
