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
