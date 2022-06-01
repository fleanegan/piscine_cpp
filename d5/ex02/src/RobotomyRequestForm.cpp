//
// Created by fschlute on 6/1/22.
//

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : \
		Form("RobotomyRequestForm", ROBOTOMY_SIGN, ROBOTOMY_EXECUTE), \
		target(target){
	std::cout << "Robotomy constructor" << std::endl;
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :\
		Form("RobotomyRequestForm", ROBOTOMY_SIGN, ROBOTOMY_EXECUTE), \
		target(other.target){
	std::cout << "Robotomy copy constructor" << std::endl;
	srand(time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Robotomy destructor" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const {
	guardExecution(bureaucrat);
	std::cout << "* drilling noises * " << std::endl;
	printProgressBar();
	if ( (rand() % 2))
		std::cout << target << " has successfully been robotomized" << std::endl;
	else
		std::cout << "robotomization failed" << std::endl;
}

void RobotomyRequestForm::printProgressBar() const {
	for (int i = 0; i < 20; ++i) {
		usleep(100000);
		std::cout << ".";
		std::cout.flush();
	}
	std::cout << std::endl;
}
