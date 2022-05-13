//
// Created by fleanegan on 12.05.22.
//

#ifndef EX06_HARL_H
#define EX06_HARL_H

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
	int filter;
public:
	void setFilter(const int &filter);

private:
	funDict complainArray[4] = {{"DEBUG", &Harl::debug},\
							{"INFO", &Harl::info},\
							{"WARNING", &Harl::warning},\
							{"ERROR", &Harl::error}};
public:
	Harl(const Harl& other);
	Harl & operator = (const Harl& other);
	~Harl();
	Harl();

	void	complain();

};


#endif //EX06_HARL_H
