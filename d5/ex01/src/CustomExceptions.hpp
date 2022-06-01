//
// Created by fschlute on 5/31/22.
//

#ifndef EX00_CUSTOMEXCEPTIONS_HPP
#define EX00_CUSTOMEXCEPTIONS_HPP

#include <exception>

class GradeTooHighException : public std::exception{
public:
	const char *what() const throw();
public:
};

class GradeTooLowException : public std::exception{
public:
	const char *what() const throw();
public:
};

class AlreadySignedException : public std::exception{
public:
	const char *what() const throw();
public:
};

#endif //EX00_CUSTOMEXCEPTIONS_HPP
