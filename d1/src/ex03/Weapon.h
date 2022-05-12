//
// Created by fleanegan on 12.05.22.
//

#ifndef EX03_WEAPON_H
#define EX03_WEAPON_H

#include <string>
#include <iostream>
#include <utility>

class Weapon {
private:
	std::string type;
public:
	explicit Weapon(std::string type);
	Weapon(const Weapon& other);
	Weapon & operator = (const Weapon& other);
	~Weapon();

	const std::string &getType() const;
	void setType(const std::string &type);
};


#endif //EX03_WEAPON_H
