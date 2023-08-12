#include <iostream>

int	main(int argc, char **argv)
{
	std::string	output;

	if (argc == 1)
		output.assign("* loud and unbearable feedback noise *");
	else
		while (*++argv)
			output.append(*argv);
	std::transform(output.begin(), output.end(), output.begin(), ::toupper);
	std::cout << output << std::endl;
}
