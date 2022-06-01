//
// Created by fschlute on 6/1/22.
//

#ifndef EX02_PRESIDENTIALPARDONFORM_HPP
#define EX02_PRESIDENTIALPARDONFORM_HPP

#define PRESIDENTIAL_SIGN 25
#define PRESIDENTIAL_EXECUTE 5

#include "Form.hpp"
#include <fstream>

class PresidentialPardonForm : public Form {
private:
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	std::string target;
public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	void execute(const Bureaucrat &bureaucrat) const;
};

#endif //EX02_PRESIDENTIALPARDONFORM_HPP
