//
// Created by fleanegan on 02.06.22.
//

#include <cstdlib>
#include <sstream>
#include <iostream>
#include <limits>
#include <cmath>
#include "Converter.hpp"

Converter::Converter(const char *input) : value(std::strtold(input, &endPtr)){
	std::cout << "input value is " << input << ", which is " << Converter::doubleToString(value) << " when saved in double" << " and directly strtold " << std::strtold(input, NULL) << std::endl;
}

bool Converter::isValidInput() const{
	if (*endPtr != 0)
		return false;
	return true;
}

Converter::~Converter() {

}

template<typename T>
bool isUnderflow(long double value) {
	if(std::numeric_limits<T>::is_signed){
		// int
		if (value < std::numeric_limits<T>::min() \
		|| value > std::numeric_limits<T>::max())
			return true;
		return false;
	}
	else
	{
		if (isinfl(value) == false && fabsl(value) > std::numeric_limits<T>::max())
			return true;
		return false;
	}
}

std::string Converter::interpretAsChar() const {
	char candidate = static_cast<char>(value);

	if (isUnderflow<char>(value))
		return (std::string("impossible"));
	if (std::isalnum(candidate))
		return std::string(1, candidate);
	return std::string("undisplayable");
}

std::string Converter::interpretAsInt() const {
	if (isUnderflow<int>(value))
		return (std::string("impossible"));
	return doubleToString(value);
}

std::string Converter::interpretAsDouble() const {
	if (isUnderflow<double>(value))
		return ("impossible");
	return doubleToString(value);
}

std::string Converter::interpretAsFloat() const {
	std::string result = doubleToString(value);

	if ((isinfl(value) == false) && (fabsl(value) > std::numeric_limits<float>::max()))
		return (std::string("impossible"));
	result = decorateResultWithTrailingFloatF(result);
	return result;
}

std::string &Converter::decorateResultWithTrailingFloatF(std::string &result) const {
	if (isinf(value) == false && isnan(value) == false && result.find('.') == std::string::npos)
		result += ".0f";
	else
		result += "f";
	return result;
}

std::string Converter::doubleToString(double input) {
	std::string result;
	std::ostringstream streamObj;

	streamObj << input;
	result = streamObj.str();
	return result;
}
