//
// Created by fleanegan on 11.05.22.
//

#include "Zombie.h"

Zombie* newZombie(std::string name)
{
	try{
		Zombie *result = new Zombie(name);
		return (result);
	}
	catch (const std::exception & e){
		std::cerr << "memory allocation failure" << std::endl;
		return (NULL);
	}
}