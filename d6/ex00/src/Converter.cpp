//
// Created by fleanegan on 02.06.22.
//

#include <cstdlib>
#include <sstream>
#include <iostream>
#include <limits>
#include <cmath>
#include <typeinfo>
#include <cerrno>

#include "Converter.hpp"

Converter::Converter(const char *input) : \
		isValidInput(canStoreInputInDouble(input)){
	if (! isValidInput)
		std::cerr << "warning, the input is not valid" << std::endl;
}

bool Converter::canStoreInputInDouble(const char *input) {
	char *endPtr;
	std::string tmp(input);

	if (tmp.length() == 1 && std::isalpha(tmp.c_str()[0]))
	{
		value = static_cast<double>(tmp.c_str()[0]);
		return true;
	}
	else
	{
		removeLastFInInputIfValid(tmp);
		errno = 0;
		value = strtod(tmp.c_str(), &endPtr);
	}
	return errno == 0 && *endPtr == 0;
}

Converter::~Converter() {

}

template<typename T>
bool Converter::isUnderflow() const {
	if(typeid(T) == typeid(int) || typeid(T) == typeid(char)){
		if (value < std::numeric_limits<T>::min() || value > std::numeric_limits<T>::max())
			return true;
		return false;
	}
	else if ((fabs(value) > std::numeric_limits<T>::max()) && !isinf(value))
		return true;
	return false;
}

std::string Converter::interpretAsChar() const {
	char candidate = static_cast<char>(value);

	if (isUnderflow<char>() || ! isValidInput)
		return "impossible";
	if (std::isprint(candidate))
		return std::string(1, candidate);
	return "not printable";
}

std::string Converter::interpretAsInt() const {
	if (isUnderflow<int>() || ! isValidInput || isnan(value))
		return "impossible";
	return toString<int>(value);
}

std::string Converter::interpretAsDouble() const {
	if (isUnderflow<double>() || ! isValidInput)
		return "impossible";
	return toString<double>(value);
}

std::string Converter::interpretAsFloat() const {
	if (isUnderflow<float>() || ! isValidInput)
		return "impossible";
	return toString<float>(value);
}

std::string &Converter::decorateResultWithTrailingDotZero(std::string &result, double value) {
	if (isinf(value) == false && isnan(value) == false && result.find('.') == std::string::npos)
		result += ".0";
	return result;
}

template<typename T>
std::string Converter::toString(double input) {
	std::string result;
	std::ostringstream streamObj;

	streamObj << static_cast<T>(input);
	result = streamObj.str();
	result = formatString < T > (input, result);
	return result;
}

template<typename T>
std::string &Converter::formatString(double input, std::string &result) {
	if (typeid(T) == typeid(float) || typeid(T) == typeid(double))
		result = decorateResultWithTrailingDotZero(result, input);
	if (typeid(T) == typeid(float))
		result += "f";
	return result;
}

std::ostream &operator<<(std::ostream &os, const Converter &converter) {
	os << "char: " << converter.interpretAsChar() << std::endl << \
	"int: " << converter.interpretAsInt() << std::endl << \
	"float: " << converter.interpretAsFloat() << std::endl << \
	"double: " << converter.interpretAsDouble() << std::endl;
	return os;
}

void Converter::removeLastFInInputIfValid(std::string &tmp) const {
	if (tmp.at(tmp.length() - 1) == 'f' && tmp != "inf" && tmp != "-inf" && tmp != "+inf" && tmp != "nan")
		tmp.at(tmp.length() - 1) = '\0';
}
