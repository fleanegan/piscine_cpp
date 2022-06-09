#include <iostream>
#include <vector>
#include "easyfind.hpp"

#ifndef TESTING
template <typename T>
int printSearchResult(std::vector<T> &container, const typename std::vector<T>::iterator &result);
template <typename T>
int printSearchResult(const std::vector<T> &container, const typename std::vector<T>::iterator &result);

int main() {
	static const int arr[] = {16,2,77,29};
	const std::vector<int> container(arr, arr + sizeof(arr) / sizeof(arr[0]) );
	std::vector<int>::const_iterator successfulSearch = easyfind<std::vector<int> >(container, 2);
	if (successfulSearch == container.end())
		std::cout << "did not find the element" << std::endl;
	else
		std::cout << "found " << *successfulSearch << std::endl;
	std::vector<int>::const_iterator unsuccessfulSearch = easyfind(container, 200);
	if (unsuccessfulSearch == container.end())
		std::cout << "did not find the element" << std::endl;
	else
		std::cout << "found " << *unsuccessfulSearch << std::endl;

	static const float arrString[] = {0, 2, 3, 4.324};
	std::vector<float> containerString(arrString, arrString + sizeof(arrString) / sizeof(arrString[0]) );
	std::vector<float>::iterator successfulSearchString = easyfind<std::vector<float> >(containerString, 3);
	printSearchResult(containerString, successfulSearchString);
	std::vector<float>::iterator unsuccessfulSearchString = easyfind(containerString, 200);
	printSearchResult(containerString, unsuccessfulSearchString);
	return 0;
}

template <typename T>
int printSearchResult(std::vector<T> &container, const typename std::vector<T>::iterator &result){
	if (result == container.end())
		std::cout << "did not find the element" << std::endl;
	else
		std::cout << "found " << *result << std::endl;
	return 0;
}


template <typename T>
int printSearchResult(const std::vector<int> &container, const std::vector<int>::const_iterator &result){

	if (result == container.end())
		std::cout << "did not find the element" << std::endl;
	else
		std::cout << "found " << *result << std::endl;
	return 0;
}

#endif
