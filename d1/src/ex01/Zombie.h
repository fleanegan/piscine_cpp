//
// Created by fleanegan on 11.05.22.
//

#ifndef EX00_ZOMBIE_H
#define EX00_ZOMBIE_H
#include <string>
#include <iostream>
#include <utility>

class Zombie {
private:
	std::string name;
public:
	explicit Zombie(std::string name);
	Zombie(const Zombie& other);
	Zombie & operator = (const Zombie& other);
	~Zombie();
	void announce(void);

	Zombie();

	void setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name);

#endif //EX00_ZOMBIE_H
