#include <iostream>
#include "PhoneBook.h"

void    addContactFromUserInput(PhoneBook &b);
void    searchOnUserInput(PhoneBook &b);
int     to_int(char const *s);

#ifndef TESTING

int main(){
	PhoneBook b;
	std::string input;
	while (1)
	{
		std::cout << "$:";
		if (! getline(std::cin,input))
			return (0);
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

	b.print_search_results(input);
	std::cout << "enter the index of the contact you want to display:";
	if (! getline(std::cin,input))
		return ;
	try{
		index = to_int(input.c_str());
	}
	catch (const std::exception & e){
		std::cerr << "A NUMBER! YOU HAVE TO PRINT A NUMBER!" << std::endl;
		return ;
	}
	try {
		b.revealContactDetailsByIndex(index);
	}
	catch (const std::exception &e){
		std::cerr << "OI MATE! ENTER A VALID INDEX!" << std::endl;
		return ;
	}
}

void addContactFromUserInput(PhoneBook &b) {
	std::string fName;
	std::string lName;
	std::string nName;
	std::string pNumber;
	std::string dSecret;

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

int to_int(const char *s) {
	int		result;
	bool	negate;

	if ( s == NULL || *s == '\0' )
	    throw std::invalid_argument("null or empty string argument");
	negate = (s[0] == '-');
	if ( *s == '+' || *s == '-' )
		++s;
	if ( *s == '\0')
		throw std::invalid_argument("sign character only.");
	result = 0;
	while(*s)
	{
		if ( *s < '0' || *s > '9' || result >= MAX_CONTACT_COUNT)
		    throw std::invalid_argument("invalid input string");
		result = result * 10  - (*s - '0');  //assume negative number
		++s;
	}
	return negate ? result : -result; //-result is positive!
}

#endif