#include "Harl.h"

#ifndef TESTING

int main(int argc, char **argv) {
	Harl		h;
	std::string	input;

	if (argc != 2)
		return (1);
	input = argv[1];
	if (input == "DEBUG")
		h.setFilter(0);
	else if (input == "INFO")
		h.setFilter(1);
	else if (input == "WARNING")
		h.setFilter(2);
	else if (input == "ERROR")
		h.setFilter(3);
	else
		h.setFilter(4);
	h.complain();
	return (0);
}

#endif