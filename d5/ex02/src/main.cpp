#include "Bureaucrat.hpp"

#ifndef TESTING

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(){
	Bureaucrat jp("hp", 1);
	Bureaucrat jc("jc", 149);
	ShrubberyCreationForm f("home");
	RobotomyRequestForm rrr("Grated Cheddar Cheese");
	PresidentialPardonForm ppp("Jean-Luc");
	f.beSigned(jp);
	rrr.beSigned(jp);
	ppp.beSigned(jp);
	try {
		f.execute(jc);
	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
	f.execute(jp);
	rrr.execute(jp);
	ppp.execute(jp);
	return (0);

}

#endif