//
// Created by fleanegan on 10.05.22.
//

#include "Contact.h"

Contact::Contact(std::string fName,
				 std::string lName,
				 std::string nName,
				 std::string pNumber,
				 std::string dSecret) :
				 firstName(fName),
				 lastName(lName),
				 nickName(nName),
				 phoneNumber(pNumber),
				 darkestSecret(dSecret){
	if (firstName.empty() \
		|| lastName.empty() \
		|| nickName.empty() \
		|| phoneNumber.empty() \
		|| darkestSecret.empty())
		throw std::exception();
}

int Contact::isContainingSearchString(std::string &str) {
	if (firstName.find(str) != std::string::npos \
		|| firstName.find(str) != std::string::npos\
		|| lastName.find(str) != std::string::npos\
		|| nickName.find(str) != std::string::npos\
		|| phoneNumber.find(str) != std::string::npos\
		|| darkestSecret.find(str) != std::string::npos)
		return (1);
	return 0;
}

void	printField(std::string &fieldName) {
	int			len;
	int			count_char_to_print;
	std::string	res = "          |";

	len = (int) fieldName.length();
	count_char_to_print = len;
	if (len >= FIELD_WIDTH_PRINT)
		count_char_to_print = FIELD_WIDTH_PRINT;
	for (int i = 0; i < count_char_to_print; ++i)
		res.at(FIELD_WIDTH_PRINT - count_char_to_print + i) = fieldName.at(i);
	if (len != count_char_to_print)
		res.at(FIELD_WIDTH_PRINT - 1) = '.';
	std::cout << res;
}

void Contact::showOverview() {
	std::cout << "|";
	printField(firstName);
	printField(lastName);
	printField(nickName);
	std::cout << "\n";
}

void Contact::showDetails() {
	std::cout << "first name:     " << firstName  << std::endl ;
	std::cout << "last name:      " << lastName  << std::endl ;
	std::cout << "nick name:      " << nickName  << std::endl ;
	std::cout << "phone number:   " << phoneNumber  << std::endl ;
	std::cout<< "darkest secret: " << darkestSecret  << std::endl ;
}

Contact::Contact() {

}

Contact &Contact::operator=(const Contact &from) {
	swap(from);
	return *this;
}

Contact::Contact(const Contact & from) {
	swap(from);
}

void Contact::swap(const Contact &with) {
	firstName = with.firstName;
	lastName = with.lastName;
	nickName = with.nickName;
	phoneNumber = with.phoneNumber;
	darkestSecret = with.darkestSecret;
}
