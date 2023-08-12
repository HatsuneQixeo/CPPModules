#include <iostream>

std::string	megaphone(std::string str)
{
	for (unsigned int i = 0; i < str.size(); i++)
		str[i] = toupper(str[i]);
	return (str);
}

int	main(int argc, char **argv)
{
	std::string	output;

	if (argc == 1)
		output.assign("* loud and unbearable feedback noise *");
	else
	{
		while (*++argv != NULL)
			output.append(*argv);
	}
	std::cout << megaphone(output) << std::endl;
}
