#include "Harl.h"

#ifndef TESTING

int main() {
	Harl h;
	h.complain("banana");
	h.complain("INFO");
	h.complain("DEBUG");
	h.complain("WARNING");
	h.complain("ERROR");
	return (0);
}

#endif