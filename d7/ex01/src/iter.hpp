//
// Created by fschlute on 6/7/22.
//

#ifndef EX00_FUNCTIONS_HPP
#define EX00_FUNCTIONS_HPP


template<typename T>
void iter(T *a, int len, void(*iterFunction)(T*)) {
	for (int i = 0; i < len; ++i) {
		iterFunction(&a[i]);
	}
}

#endif //EX00_FUNCTIONS_HPP
