//
// Created by fschlute on 5/31/22.
//

#ifndef EX00_BUREAUCRAT_HPP
#define EX00_BUREAUCRAT_HPP

#define MAX_GRADE 150
#define MIN_GRADE 1

#include <string>
#include "CustomExceptions.hpp"
class Bureaucrat {
private:
	const std::string name;
	short grade;
public:
	Bureaucrat(const std::string &name, short initGrade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &);
	~Bureaucrat();

	std::string getName() const;
	short getGrade() const;
};

#endif //EX00_BUREAUCRAT_HPP
