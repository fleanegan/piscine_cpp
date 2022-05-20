#include "Zombie.h"

#define HORDE_SIZE 10
#ifndef TESTING

int main(){
	Zombie	*horde;

	horde = zombieHorde(HORDE_SIZE, "peter");
	for (int i = 0; i < HORDE_SIZE ; ++i) {
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}

#endif