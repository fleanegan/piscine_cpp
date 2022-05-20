#include <iostream>
#include "fstream"

int         initFiles(int argc, char *const *argv, std::ifstream &inFile, std::ofstream &outFile);
bool        isCurrentWordReplaceeCandidate(\
			std::ifstream &inFile, const std::string &current_word, const std::string &replacee);
void        doReplacement(std::ofstream &outFile, std::string &current_word, const std::string &replacer);
void        writeLeftoversToOutfile(\
			const std::string &replacee, const std::string &replacer, std::ofstream &outFile, std::string &current_word);
std::string &appendNextCharIfEmptyReplacementCandidate(std::ifstream &inFile, std::string &replacementCandidate);
void        writeReplacerIfMatch(\
			const std::string &replacee, const std::string &replacer, std::ofstream &outFile, std::string &current_word);
void        buildReplacementCandidate(const std::string &replacee, std::ifstream &inFile, std::string &current_word);

#ifndef TESTING

int main(int argc, char *argv[]) {
	std::ifstream	inFile;
	std::ofstream	outFile;
	std::string		replacementCandidate;
	std::string		replacee;
	std::string		replacer;

	if (initFiles(argc, argv, inFile, outFile))
		return (-1);
	replacee = argv[2];
	replacer = argv[3];
	while (inFile.peek() != EOF) {
		buildReplacementCandidate(replacee, inFile, replacementCandidate);
		writeReplacerIfMatch(replacee, replacer, outFile, replacementCandidate);
		replacementCandidate = appendNextCharIfEmptyReplacementCandidate(inFile, replacementCandidate);
		writeLeftoversToOutfile(replacee, replacer, outFile, replacementCandidate);
	}
	inFile.close();
	outFile.close();
	return (0);
}

void	buildReplacementCandidate(\
		const std::string &replacee, std::ifstream &inFile, std::string &current_word) {
	while (isCurrentWordReplaceeCandidate(inFile, current_word, replacee)\
			&& current_word != replacee)
		current_word += inFile.get();
	std::cout << current_word << std::endl;
}

void	writeReplacerIfMatch(\
		const std::string &replacee, const std::string &replacer, std::ofstream &outFile, std::string &current_word) {
	if (current_word == replacee && replacee.length() != 0)
		doReplacement(outFile, current_word, replacer);
}

std::string	&appendNextCharIfEmptyReplacementCandidate(\
			std::ifstream &inFile, std::string &replacementCandidate) {
	if (inFile.peek() != EOF && replacementCandidate.empty())
		replacementCandidate = inFile.get();
	return replacementCandidate;
}

void	writeLeftoversToOutfile(\
		const std::string &replacee, const std::string &replacer, std::ofstream &outFile, std::string &current_word) {
	if (current_word != replacee)
		outFile << current_word;
	else
		doReplacement(outFile, current_word, replacer);
	current_word.clear();
}

void	doReplacement(\
		std::ofstream &outFile, std::string &current_word, const std::string &replacer) {
	current_word.clear();
	outFile << replacer;
}

bool	isCurrentWordReplaceeCandidate(\
		std::ifstream &inFile, const std::string &current_word, const std::string &replacee) {
	return inFile.peek() != EOF && replacee.find(current_word) == 0;
}

int initFiles(\
	int argc, char *const *argv, std::ifstream &inFile, std::ofstream &outFile) {
	std::string		inFileName;
	std::string		outFileName;

	if (argc != 4)
		return (1);
	inFileName = argv[1];
	outFileName = inFileName + ".replace";
	inFile.open(inFileName.c_str());
	outFile.open(outFileName.c_str());
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