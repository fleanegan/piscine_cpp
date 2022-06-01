//
// Created by fschlute on 5/31/22.
//

#include "CustomExceptions.hpp"

const char *GradeTooHighException::what() const throw() {
	return "Grade is too high!\n";
}

const char *GradeTooLowException::what() const throw() {
	return "Grade is too low!\n";
}

const char *AlreadySignedException::what() const throw() {
	return "This Form has already been signed!\n";
}

const char *NotSignedYetException::what() const throw() {
	return "This Form has not been signed yet!\n";
}
