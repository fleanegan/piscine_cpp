#include <iostream>
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

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
	AMateria *c = new Cure();
	AMateria *c1 = new Ice();
	me->equip(c); // should add
	me->equip(c); // should not add again
	me->equip(c); // should not add again
	me->equip(c); // should not add again
	me->unequip(2); // out of range, does not do anything
	me->unequip(0); // removes c from inventory but does not delete its
	delete c;	// since we are not allowed to delete in unequip
	c = new Cure();
	me->equip(c);
	me->unequip(42);
	me->use(0, *me);
	you.equip(c1);
	*(Character *)me = you;
	me->use(0, *me);
	std::cout << " me name :" << me->getName() << std::endl;
	delete me;
	MateriaSource m;
	m.createMateria("cure");
	m.learnMateria(new Cure());
	AMateria *c2 = m.createMateria("cure");
	you.equip(c2);
	you.use(1, you);
	return 0;
}