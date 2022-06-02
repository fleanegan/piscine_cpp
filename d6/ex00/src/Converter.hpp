//
// Created by fleanegan on 02.06.22.
//

#ifndef EX00_CONVERTER_HPP
#define EX00_CONVERTER_HPP

#include <string>

class Converter {
private:
	const long double value;
	char *endPtr;

	Converter(const Converter &other);
	Converter &operator=(const Converter &);
	std::string &decorateResultWithTrailingFloatF(std::string &result) const ;
	bool isValidInput() const;
public:
	Converter(const char *input);
	~Converter();
	std::string interpretAsInt() const;
	std::string interpretAsChar() const;
	static std::string doubleToString(double input) ;
	std::string interpretAsDouble() const;
	std::string interpretAsFloat() const;
};

#endif //EX00_CONVERTER_HPP
