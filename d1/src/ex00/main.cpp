#include "Zombie.h"

#ifndef TESTING

int main(){
	Zombie z("test");
	Zombie *newbie = newZombie("Epoisses");
	randomChump("Cantal");
	delete newbie;
}

#endif