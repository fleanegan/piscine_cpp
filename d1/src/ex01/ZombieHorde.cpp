//
// Created by fleanegan on 11.05.22.
//

#include "Zombie.h"

Zombie *zombieHorde(int N, std::string name) {
	Zombie *result;

	try{
		result = new Zombie[N];
		for (int i = 0; i < N; ++i)
			result[i].setName(name);
	}
	catch (const std::exception & e){
		std::cerr << "memory allocation failure" << std::endl;
	}
	return (result);
}
