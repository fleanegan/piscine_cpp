#include <iostream>
#include "sedIsForLoosers.h"

int initFiles(int argc, char *const *argv, std::ifstream &inFile, std::ofstream &outFile);
std::string createSeparator(std::ifstream &inFile);
std::string replace(const std::string &word, const char *replacee, const char *replacer);

std::string substitute(const std::string &input, const std::string &replacee, const std::string &replacer) {
	std::string result;
	size_t start;
	size_t end;

	start = 0;
	while (1)
	{
		end = input.find(replacee, start);
		if (end == std::string::npos)
		{
			if (result.length() == 0)
				return (input);
			result += input.substr(start);
			return (result);
		}
		result += input.substr(start, end - start);
		start = end + replacee.length();
		result += replacer;
	}
}

#ifndef TESTING

int main(int argc, char *argv[]) {
	std::ifstream	inFile;
	std::ofstream	outFile;
	std::string		current_word;

	if (initFiles(argc, argv, inFile, outFile))
		return (-1);
	while (inFile >> current_word) {
		outFile << replace(current_word, argv[2], argv[3]);
		outFile << createSeparator(inFile);
	}
	inFile.close();
	outFile.close();
	return (0);
}

std::string replace(const std::string &word, const char *replacee, const char *replacer) {
	if (word == replacee)
		return (replacer);
	else
		return (word);
}

std::string createSeparator(std::ifstream &inFile) {
	if (inFile.peek() != EOF)
	{
		if (inFile.peek() == '\n')
			return ("\n");
		return(" ");
	}
	return ("");
}

int initFiles(int argc, char *const *argv, std::ifstream &inFile, std::ofstream &outFile) {
	std::string		inFileName;
	std::string		outFileName;

	inFileName = argv[1];
	outFileName = inFileName + ".replace";
	if (argc != 4)
		return (1);
	inFile.open(inFileName);
	outFile.open(outFileName);
	if (inFile.is_open() == false)
	{
		std::cerr << "the file " << argv[1] << " does not exist" << std::endl;
		return (-1);
	}
	if (outFile.is_open() == false)
	{
		inFile.close();
		std::cerr << "the file " << argv[1] << ".replace cannot be opened for write" << std::endl;
		return (-1);
	}
	return (0);
}

#endif