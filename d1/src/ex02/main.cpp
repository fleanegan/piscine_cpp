#include <iostream>

std::string string_to_upper(const char *in);

int main(){
	std::string	brain;
	const char	*stringPTR;
	std::string &stringREF = brain;

	brain = "HI THIS IS BRAIN";
	stringPTR = brain.c_str();

	std::cout << "printing addresses" << std::endl;
	std::cout << "string address = " << &(brain) << std::endl;
	std::cout << "reference address = " << &stringREF << std::endl;
	std::cout << "pointer address = " << (void *) stringPTR << std::endl;
	std::cout << "printing values" << std::endl;
	std::cout << "string = " << brain << std::endl;
	std::cout << "reference = " << stringREF << std::endl;
	std::cout << "pointer = " << stringPTR << std::endl;
}