//
// Created by fschlute on 6/1/22.
//

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : \
		Form("PresidentialPardonForm", PRESIDENTIAL_SIGN, PRESIDENTIAL_EXECUTE), \
		target(target){
	std::cout << "Presidential constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :\
		Form("PresidentialPardonForm", PRESIDENTIAL_SIGN, PRESIDENTIAL_EXECUTE), \
		target(other.target){
	std::cout << "Presidential copy constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Presidential destructor" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const {
	guardExecution(bureaucrat);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}