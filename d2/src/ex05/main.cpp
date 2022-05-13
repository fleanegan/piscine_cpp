#include "Harl.h"

#ifndef TESTING

int main() {
	Harl h;
	h.complain("banana");
	h.complain("info");
	h.complain("debug");
	h.complain("warning");
	h.complain("error");
	return (0);
}

#endif