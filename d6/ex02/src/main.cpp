#include <cstdlib>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#ifndef TESTING

Base * generate(void){
	srand (time(NULL));
	int tmp = rand() % 99;
	if (tmp <= 33)
	{
		std::cout << "Generating an A" << std::endl;
		return new A();
	}
	if (tmp > 33 && tmp <= 66)
	{
		std::cout << "Generating a B" << std::endl;
		return new B();
	}
	std::cout << "Generating a C" << std::endl;
	return new C();
};

void identify(Base* p){
	Base *result;

	result = dynamic_cast<A *>(p);
	if (result != NULL){
		std::cout << "A" << std::endl;
		return ;
	}
	result = dynamic_cast<B *>(p);
	if (result != NULL){
		std::cout << "B" << std::endl;
		return ;
	}
	result = dynamic_cast<C *>(p);
	if (result != NULL){
		std::cout << "C" << std::endl;
		return ;
	}
	std::cout << "wtf" << std::endl;
};

void identify(Base& p){
	try {
		dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::exception &e){}
	try {
		dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::exception &e){}
	try {
		dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::exception &e){}
};

int main(){
	Base *toBeTested = generate();
	identify(toBeTested);
	identify(*toBeTested);
	return 0;
}

#endif
