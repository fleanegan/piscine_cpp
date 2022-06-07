#include <iostream>
#include <stdint.h>
#include "Data.hpp"

#ifndef TESTING

uintptr_t serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
};

Data* deserialize(uintptr_t raw){
	return reinterpret_cast<Data *>(raw);
};

int main(){
	Data *test = new Data();
	test->arr[0] = 1;
	test->arr[1] = 4;
	test->arr[2] = 2;
	uintptr_t serAddr = serialize(test);
	Data *deSerAddr = deserialize(serAddr);
	std::cout << "orig: " << test << ", as ptr: " << serAddr << " deserialized: " << deSerAddr << std::endl;
	std::cout << "0: " << test->arr[0] << " 1: " << test->arr[1] << " 2: " << test->arr[2] << std::endl;
}

#endif
