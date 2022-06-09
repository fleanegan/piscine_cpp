//
// Created by fschlute on 6/7/22.
//

#ifndef EX00_FUNCTIONS_HPP
#define EX00_FUNCTIONS_HPP

template<typename T>
void swap(T &a, T &b){
	T tmp = a;

	a = b;
	b = tmp;
}

//todo: discuss during defense
//template<typename T>
//T min(T &a, T &b){
//	if (a < b)
//		return a;
//	return b;
//}
//
//template<typename T>
//T max(T &a, T &b){
//	if (a > b)
//		return a;
//	return b;
//}

template<typename T>
T min(T a, T b){
	if (a < b)
		return a;
	return b;
}

template<typename T>
T max(T a, T b){
	if (a > b)
		return a;
	return b;
}

#endif //EX00_FUNCTIONS_HPP
