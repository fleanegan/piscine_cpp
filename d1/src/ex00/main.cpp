#include "Zombie.h"

#ifndef TESTING

int main(){
	Zombie z("test");
	Zombie *newbie = newZombie("Epoisses");
	randomChump("Cantal");

	z.announce();
	newbie->announce();
	delete newbie;
}

#endif