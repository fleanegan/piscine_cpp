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
#endif //EX00_EASYFIND_HPP
