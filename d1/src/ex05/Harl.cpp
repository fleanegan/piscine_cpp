//
// Created by fleanegan on 12.05.22.
//

#include "Harl.h"

Harl::Harl(const Harl &other) : complainArray(){
	complainArray[0].name = "DEBUG";
	complainArray[0].function = &Harl::debug;
	complainArray[1].name = "INFO";
	complainArray[1].function = &Harl::info;
	complainArray[2].name = "WARNING";
	complainArray[2].function = &Harl::warning;
	complainArray[3].name = "ERROR";
	complainArray[3].function = &Harl::error;
	(void) other;
}

Harl &Harl::operator=(const Harl &other) {
	complainArray[0].name = "DEBUG";
	complainArray[0].function = &Harl::debug;
	complainArray[1].name = "INFO";
	complainArray[1].function = &Harl::info;
	complainArray[2].name = "WARNING";
	complainArray[2].function = &Harl::warning;
	complainArray[3].name = "ERROR";
	complainArray[3].function = &Harl::error;
	return *this;
	(void) other;
}

Harl::~Harl() {

}

void Harl::debug(void)  const{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)  const{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)  const{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)  const{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	HarlMemFn	ptr;

	ptr = NULL;
	for (int i = 0; i < 4 && ptr == NULL; ++i) {
		ptr = complainArray[i].name == level ? complainArray[i].function : NULL;
	}
	if (ptr == NULL)
	{
		std::cerr << "level did not match any of Harls know how" << std::endl;
		return ;
	}
	(this->*ptr)();
}

Harl::Harl() {
	complainArray[0].name = "DEBUG";
	complainArray[0].function = &Harl::debug;
	complainArray[1].name = "INFO";
	complainArray[1].function = &Harl::info;
	complainArray[2].name = "WARNING";
	complainArray[2].function = &Harl::warning;
	complainArray[3].name = "ERROR";
	complainArray[3].function = &Harl::error;
}
