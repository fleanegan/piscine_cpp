//
// Created by fleanegan on 08.06.22.
//

#ifndef EX00_EASYFIND_HPP
#define EX00_EASYFIND_HPP

template<typename T>
typename T::iterator easyfind(T &container, int toFind){
	typename T::iterator iter = container.begin();
	typename T::iterator end = container.end();

	while (iter != end){
		if (*iter == toFind)
			return iter;
		++iter;
	}
	return end;
}

template<typename T>
typename T::const_iterator easyfind(const T &container, int toFind){
	typename T::const_iterator iter = container.begin();
	typename T::const_iterator end = container.end();

	while (iter != end){
		if (*iter == toFind)
			return iter;
		++iter;
	}
	return iter;
}
#endif //EX00_EASYFIND_HPP
