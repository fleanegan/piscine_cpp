//
// Created by fschlute on 6/1/22.
//

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : \
		Form("ShrubberyCreationForm", SHRUBBERY_SIGN, SHRUBBERY_EXECUTE), \
		target(target){
	std::cout << "Shrubbery constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :\
		Form("ShrubberyCreationForm", SHRUBBERY_SIGN, SHRUBBERY_EXECUTE), \
		target(other.target){
	std::cout << "Shrubbery copy constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery destructor" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const {
	guardExecution(bureaucrat);
	std::ofstream out;
	out.exceptions ( std::ofstream::failbit | std::ofstream::badbit );
	out.open((target + "_shrubbery").c_str());
	out << TREE;
	out.close();
}