//
// Created by fschlute on 5/31/22.
//

#ifndef EX00_BUREAUCRAT_HPP
#define EX00_BUREAUCRAT_HPP

#define MAX_GRADE 1
#define MIN_GRADE 150

#include <string>
#include <ostream>
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

	void decrementGrade();
	void incrementGrade();
	std::string getName() const;
	short getGrade() const;
};
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);


#endif //EX00_BUREAUCRAT_HPP
