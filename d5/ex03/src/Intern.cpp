//
// Created by fschlute on 6/1/22.
//

#include "Intern.hpp"

Intern::Intern() {

}

Intern::Intern(const Intern &other) {
	(void) other;
}

Intern &Intern::operator=(const Intern &other) {
	(void) other;
	return *this;
}

Intern::~Intern() {

}
#define NUMBER_OF_KNOWN_FORMS 4

Form *Intern::makeForm(const std::string &formName, const std::string &target) const {
	const std::string existingForms[NUMBER_OF_KNOWN_FORMS] = \
		{"ShrubberyCreationForm", \
		"RobotomyRequestForm", \
		"PresidentialPardonForm"};
	int classToInstantiate = -1;

	for (int i = 0; i < NUMBER_OF_KNOWN_FORMS && classToInstantiate == -1; ++i) {
		if (formName == existingForms[i])
			classToInstantiate = i;
	}
	std::cout << "Intern creates " << formName << std::endl;
	switch (classToInstantiate) {
		case 0: return new ShrubberyCreationForm(target);
		case 1: return new RobotomyRequestForm(target);
		case 2: return new PresidentialPardonForm(target);
		default: {
			std::cout << "The form " << formName << " does not exist" << std::endl;
			return NULL;
		}
	}
}
