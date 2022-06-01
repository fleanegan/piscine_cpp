//
// Created by fschlute on 6/1/22.
//

#ifndef EX02_ROBOTOMYREQUESTFORM_HPP
#define EX02_ROBOTOMYREQUESTFORM_HPP

#define ROBOTOMY_SIGN 72
#define ROBOTOMY_EXECUTE 45

#include "Form.hpp"
#include <fstream>
#include <unistd.h>
#include <cstdlib>

class RobotomyRequestForm : public Form {
private:
	std::string target;

	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	void printProgressBar() const;
public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	void execute(const Bureaucrat &bureaucrat) const;
};

#endif //EX02_ROBOTOMYREQUESTFORM_HPP
