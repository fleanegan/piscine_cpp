//
// Created by fschlute on 5/10/22.
//

#ifndef PISCINE_CPP_PHONEBOOK_H
#define PISCINE_CPP_PHONEBOOK_H


class PhoneBook
{
private:

public:
	PhoneBook();
	PhoneBook(const PhoneBook & phoneBook);
	PhoneBook & operator = (const PhoneBook & phoneBook);
	virtual ~PhoneBook();
};


#endif //PISCINE_CPP_PHONEBOOK_H
