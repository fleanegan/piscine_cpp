#include <iostream>
#include "Character.hpp"
#include "Cure.hpp"

ICharacter *generateTestCharacter(const std::string &name){
	Character i(name);
	Character j(i);
	Character *k = new Character("");
	*k = j;
	return k;
}

int	main(){
	ICharacter *me = generateTestCharacter("Gorgonzola");
	Character you("Parmeggiano");
	std::cout << "name " << me->getName() << std::endl;
	Cure *c = new Cure();
	Cure *c1 = new Cure();
	me->equip(c);
	me->equip(c);
	me->equip(c);
	me->equip(c);
	me->unequip(2);
	me->unequip(0);
	c = new Cure();
	me->equip(c);
	me->unequip(42);
	me->use(0, *me);
	you.equip(c1);
	*(Character *)me = you;
	me->use(0, *me);
	std::cout << " me name :" << me->getName() << std::endl;
	delete me;
	return 0;
}