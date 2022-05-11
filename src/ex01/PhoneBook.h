//
// Created by fschlute on 5/10/22.
//

#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#define MAX_CONTACT_COUNT 8
#include "Contact.h"
#include <iostream>

class PhoneBook
{
private:
	int		contactIndex;
	Contact	contacts[MAX_CONTACT_COUNT];
	void	free_space_for_contact();
public:
	PhoneBook	();
	PhoneBook	(const PhoneBook & phoneBook);
	PhoneBook 	& operator = (const PhoneBook & phoneBook);
	~PhoneBook	();
	void		add_contact(const Contact &contact);
	void		print_search_results(std::string &str);
	void		revealContactDetailsByIndex(int i);
};

#endif //PHONEBOOK_H
