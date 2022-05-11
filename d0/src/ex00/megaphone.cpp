#include <iostream>

std::string string_to_upper(const char *in);

int main(int argc, char *argv[]){
	std::string s;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< std::endl;
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			s = string_to_upper(argv[i]);
			if (i < argc - 1)
				s.append(" ");
			std::cout << s;
		}
		std::cout << std::endl;
	}
	return (0);
}

std::string string_to_upper(const char *in)
{
	int j;

	std::string s = in;
	for (j = 0; j < (int) s.length(); ++j)
		s.at(j) = toupper(s.at(j));

	return s;
}
