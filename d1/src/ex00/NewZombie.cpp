//
// Created by fleanegan on 11.05.22.
//

#include "Zombie.h"

Zombie* newZombie( std::string name )
{
	Zombie *result = new Zombie(name);
	return (result);
}