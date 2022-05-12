#include <iostream>

int initFiles(int argc, char *const *argv, std::ifstream &inFile, std::ofstream &outFile);
std::string createSeparator(std::ifstream &inFile);
std::string replace(const std::string &word, const char *replacee, const char *replacer);

#ifndef TESTING
#include "fstream"

int main(int argc, char *argv[]) {
	std::ifstream	inFile;
	std::ofstream	outFile;
	std::string		current_word;

	if (initFiles(argc, argv, inFile, outFile))
		return (-1);
	outFile << createSeparator(inFile);
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
	std::string	result;
	while (inFile.peek() != EOF && (inFile.peek() == '\n' || std::isspace(inFile.peek())))
		result += inFile.get();
	return (result);
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