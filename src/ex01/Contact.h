//
// Created by fleanegan on 10.05.22.
//

#ifndef EX01_CONTACT_H
#define EX01_CONTACT_H
#define FIELD_WIDTH_PRINT 10

#include <string>
#include <iostream>


class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	void swap(const Contact &with);
public:
	Contact	();
	Contact	(std::string fName,
				std::string lName,
				std::string nName,
				std::string pNumber,
				std::string dSecret);
	Contact & operator = (const Contact & from);
	Contact	(const Contact & from);
	int		isContainingSearchString(std::string &str);
	void	showOverview(void);
	void	showDetails();
};


#endif //EX01_CONTACT_H
