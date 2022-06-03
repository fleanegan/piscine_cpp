#include <cmath>
#include "test_utils.h"

TEST(converter, printInt){
	Converter converter("42");

	std::string output = converter.interpretAsInt();
	ASSERT_STREQ("42", output.c_str());
}

TEST(converter, printNegativeInt){
	Converter converter("-42");

	std::string output = converter.interpretAsInt();
	ASSERT_STREQ("-42", output.c_str());
}

TEST(converter, printMinInt){
	Converter converter(std::to_string(static_cast<long int>(std::numeric_limits<int>::min()) - 1).c_str());

	std::string output = converter.interpretAsInt();
	ASSERT_STREQ("impossible", output.c_str());
}

TEST(converter, printMaxInt){
	Converter converter(std::to_string(static_cast<long int>(std::numeric_limits<int>::max()) + 1).c_str());

	std::string output = converter.interpretAsInt();
	ASSERT_STREQ("impossible", output.c_str());
}

TEST(converter, printDoubleTooBigForIntAsInt){
	std::basic_string<char> input = std::to_string(std::numeric_limits<double>::max());
	Converter converter(input.c_str());

	std::string output = converter.interpretAsInt();
	ASSERT_STREQ("impossible", output.c_str());
}

TEST(converter, printInputAsChar){
	Converter converter("65");

	std::string output = converter.interpretAsChar();
	ASSERT_STREQ("A", output.c_str());
}

TEST(converter, printInputAsUnprintableChar){
	Converter converter("0");

	std::string output = converter.interpretAsChar();
	ASSERT_STREQ("not printable", output.c_str());
}

TEST(converter, printDoubleTooBigForFloatAsFloat){
	std::basic_string<char> input = std::to_string(std::numeric_limits<double>::max());
	Converter converter(input.c_str());

	std::string output = converter.interpretAsFloat();
	ASSERT_STREQ("impossible", output.c_str());
}

TEST(converter, floatOutputsZeroWithATrailingF){
	Converter converter("0");

	std::string output = converter.interpretAsFloat();
	ASSERT_STREQ("0.0f", output.c_str());
}

TEST(converter, floatCheckLowerBoundWithATrailingF){
	std::basic_string<char> input = std::to_string(-1. * std::numeric_limits<double>::max());
	Converter converter(input.c_str());

	std::string output = converter.interpretAsFloat();
	ASSERT_STREQ("impossible", output.c_str());
}

TEST(converter, floatOutputsWithATrailingF){
	Converter converter("0.5");

	std::string output = converter.interpretAsFloat();
	ASSERT_STREQ("0.5f", output.c_str());
}

TEST(converter, floatOutputsWithATrailingFInt){
	Converter converter("inf");

	std::string output = converter.interpretAsFloat();
	ASSERT_STREQ("inff", output.c_str());
}

TEST(converter, floatOutputsWithATrailingFMinusInf){
	Converter converter("-inf");

	std::string output = converter.interpretAsFloat();
	ASSERT_STREQ("-inff", output.c_str());
}

TEST(converter, floatOutputsWithATrailingFMinusNan){
	Converter converter("-nan");

	std::string output = converter.interpretAsFloat();
	ASSERT_STREQ("-nanf", output.c_str());
}

TEST(converter, floatOutputsWithATrailingFNan){
	Converter converter("nan");

	std::string output = converter.interpretAsFloat();
	ASSERT_STREQ("nanf", output.c_str());
}

TEST(converter, nan){
	Converter converter("nan");

	std::string output = converter.interpretAsFloat();
	ASSERT_STREQ("nanf", output.c_str());
}

TEST(converter, plusSignInf){
	Converter converter("+inf");

	std::string output = converter.interpretAsFloat();
	ASSERT_STREQ("inff", output.c_str());
}

TEST(converter, doubleCheckLowerBound){
	std::string s = "-279769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368";
	Converter converter(s.c_str());

	std::string output = converter.interpretAsDouble();
	ASSERT_STREQ("impossible", output.c_str());
}

TEST(converter, doubleCheckUpperBound){
	std::string s = "279769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000";
	Converter converter(s.c_str());

	std::string output = converter.interpretAsDouble();
	ASSERT_STREQ("impossible", output.c_str());
}

TEST(converter, trashInput){
	Converter converter("blablabl");

	std::string output = converter.interpretAsDouble();
	ASSERT_STREQ("impossible", output.c_str());
}