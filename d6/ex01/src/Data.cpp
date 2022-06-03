//
// Created by fleanegan on 03.06.22.
//

#include <string>
#include "Data.hpp"

Data::Data() : str(), arr() {

}

Data::Data(const Data &other) {
	*this = other;
}

Data &Data::operator=(const Data &other) {
	if (this == &other)
		return *this;
	for (int i = 0; i < 3; ++i) {
		arr[i] = other.arr[i];
	}
	str = other.str;
	return *this;
}

Data::~Data() {

}

const std::string &Data::getStr() const {
	return str;
}
