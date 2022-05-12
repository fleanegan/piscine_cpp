//
// Created by fleanegan on 12.05.22.
//

#ifndef EX03_HUMANA_H
#define EX03_HUMANA_H
#include "HumanB.h"

class HumanA : public HumanB{
public:
	HumanA(const std::string &name, const Weapon &weapon);
	HumanA(const HumanB &other);
	HumanA & operator=(const HumanB &other);
	~HumanA();
};


#endif //EX03_HUMANA_H
