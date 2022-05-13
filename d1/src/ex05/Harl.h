//
// Created by fleanegan on 12.05.22.
//

#ifndef EX03_WEAPON_H
#define EX03_WEAPON_H

#include <string>
#include <iostream>
#include <utility>

class Harl;

typedef  void (Harl::*HarlMemFn)(void) const;

typedef struct s {
	std::string name;
	HarlMemFn function;
} funDict;

class Harl {
private:
	void debug(void ) const;
	void info( void )  const;
	void warning( void )  const;
	void error( void )  const;
	funDict complainArray[4] = {{"DEBUG", &Harl::debug},\
							{"INFO", &Harl::info},\
							{"WARNING", &Harl::warning},\
							{"ERROR", &Harl::error}};
public:
	Harl(const Harl& other);
	Harl & operator = (const Harl& other);
	~Harl();
	Harl();

	void	complain(std::string level);
};


#endif //EX03_WEAPON_H
