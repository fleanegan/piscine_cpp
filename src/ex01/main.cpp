#include <iostream>
#include "PhoneBook.h"

void addContactFromUserInput(PhoneBook &b);
void searchOnUserInput(PhoneBook &b);

#ifndef TESTING

int main(){
	PhoneBook b;
	std::string input;
	while (1)
	{
		std::cout << "$:";
		std::cin >> input;
		if (input == "SEARCH")
			searchOnUserInput(b);
		if (input == "ADD")
			addContactFromUserInput(b);
		else if (input == "EXIT")
			return (0);
		input.clear();
	}
}

void searchOnUserInput(PhoneBook &b) {
	std::string input;
	int			index;

	std::cout << "search string:" << std::endl;
	getline(std::cin, input);
	b.print_search_results(input);
	std::cout << "enter the index of the contact you want to display:";
	std::cin >> index;
	try {
		b.revealContactDetailsByIndex(index);
	}
	catch (const std::exception &e){
		std::cerr << "oi mate! enter a valid index! I've had enough. Over and out." << std::endl;
		exit(1);
	}
}

void addContactFromUserInput(PhoneBook &b) {
	std::string fName;
	std::string lName;
	std::string nName;
	std::string pNumber;
	std::string dSecret;

	std::cin.ignore(1,'\n');
	std::cout << "first name:";
	getline(std::cin, fName);
	std::cout << "last name:";
	getline(std::cin, lName);
	std::cout << "nick name:";
	getline(std::cin, nName);
	std::cout << "phone number:";
	getline(std::cin, pNumber);
	std::cout << "darkest secret:";
	getline(std::cin, dSecret);
	try{
		b.add_contact(Contact(fName, lName, nName, pNumber, dSecret));
		std::cout << "Contact added" << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << "empty fields are not allowed!" << std::endl;
	}
}

#endif