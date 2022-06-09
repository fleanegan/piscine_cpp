#include <iostream>
#include "iter.hpp"

#ifndef TESTING

#define ARR_LEN 5

template <typename T>
void iterFunction(T& in){
	in++;
}

template <typename T>
void printArr(T* arr){
	for (int i = 0; i < ARR_LEN; ++i) {
		std::cout << (int) arr[i];
	}
	std::cout << std::endl;
}

int main(){
	int intArr[ARR_LEN] = {};
	char charArr[ARR_LEN] = {};
	std::cout << "int array before: ";
	printArr<int>(intArr);
	std::cout << "char array before: ";
	printArr<char>(charArr);
	iter(intArr, ARR_LEN, iterFunction);
	iter(charArr, ARR_LEN, iterFunction);
	std::cout << "int array after: ";
	printArr<int>(intArr);
	std::cout << "char array after: ";
	printArr<char>(charArr);
	return 0;
}

#endif
