//
// Created by fschlute on 5/10/22.
//

#include "PhoneBook.h"

PhoneBook::PhoneBook(void) : contactIndex(0), contacts(){
}

PhoneBook::PhoneBook(const PhoneBook &phoneBook) {
	for (int i = 0; i < phoneBook.contactIndex; ++i)
		contacts[i] = phoneBook.contacts[i];
	contactIndex = phoneBook.contactIndex;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &phoneBook) {
	if (this == &phoneBook)
		return *this;
	for (int i = 0; i < phoneBook.contactIndex; ++i)
		contacts[i] = phoneBook.contacts[i];
	contactIndex = phoneBook.contactIndex;
	return *this;
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::print_search_results(std::string &str) {
	std::cout << "|...........................................|" << std::endl;
	std::cout << "|     index|first name| last name| nick name|" << std::endl;
	for (int i = 0; i < contactIndex; ++i) {
		if (contacts[i].isContainingSearchString(str))
		{
			std::cout << "|         " << i;
			contacts[i].showOverview();
		}
	}
	std::cout << "|...........................................|" << std::endl;
}

void PhoneBook::add_contact(const Contact &contact) {
	if (contactIndex == MAX_CONTACT_COUNT)
		free_space_for_contact();
	contacts[contactIndex] = contact;
	++contactIndex;
}

void PhoneBook::free_space_for_contact() {
	for (int i = 1; i < MAX_CONTACT_COUNT; ++i)
		contacts[i - 1] = contacts[i];
	--contactIndex;
}

void PhoneBook::revealContactDetailsByIndex(int i) {
	if (i < 0 || i >= contactIndex)
		throw std::exception();
	contacts[i].showDetails();
}
