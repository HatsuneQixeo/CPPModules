#include "lib.hpp"

std::string	prompt(const std::string &request, const ft_stris ft_is)
{
	std::string	input;

	do
	{
		std::cout << request;
		getline(std::cin, input);
	} while (!ft_is(input) && std::cin.eof() == false);
	return (input);
}
