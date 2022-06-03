//
// Created by fleanegan on 02.06.22.
//

#ifndef EX00_CONVERTER_HPP
#define EX00_CONVERTER_HPP

#include <string>
#include <ostream>

class Converter {
private:
	double value;
	bool isValidInput;

	Converter(const Converter &other);
	Converter &operator=(const Converter &);
	bool canStoreInputInDouble(const char *input);
	template<typename T>
	bool isUnderflow() const;
	static std::string &decorateResultWithTrailingDotZero(std::string &result, double value);
	template<typename T>
	static std::string &formatString(double input, std::string &result);

public:
	Converter(const char *input);
	~Converter();
	std::string interpretAsInt() const;
	std::string interpretAsChar() const;
	template<typename T>
	static std::string toString(double input) ;
	std::string interpretAsDouble() const;
	std::string interpretAsFloat() const;
};

std::ostream &operator<<(std::ostream &os, const Converter &converter);

#endif //EX00_CONVERTER_HPP
