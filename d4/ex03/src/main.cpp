#include <iostream>
#include "Character.hpp"

int	main(){
	ICharacter *me = new Character("Gorgonzola");
	std::cout << "name " << me->getName() << std::endl;
	return 0;
}