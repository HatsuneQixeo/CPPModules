#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

namespace ansi
{
	const std::string	grey = "\033[0;30m";
	const std::string	red = "\033[0;31m";
	const std::string	green = "\033[0;32m";
	const std::string	yellow = "\033[0;33m";
	const std::string	blue = "\033[0;34m";
	const std::string	magenta = "\033[0;35m";
	const std::string	cyan = "\033[0;36m";

	const std::string	b_grey = "\033[0;90m";
	const std::string	b_red = "\033[0;91m";
	const std::string	b_green = "\033[0;92m";
	const std::string	b_yellow = "\033[0;93m";
	const std::string	b_blue = "\033[0;94m";
	const std::string	b_magenta = "\033[0;95m";
	const std::string	b_cyan = "\033[0;96m";

	const std::string	reset = "\033[0m";
}

template <typename T>
void	easyTest(T &container, const int find)
{
	const T::iterator	it_find = easyfind(container, find);

	std::cout << ansi::yellow << std::setw(2) << find << ": ";
	if (it_find != container.end())
		std::cout << ansi::green << "Found in index: " << std::distance(container.begin(), it_find);
	else
		std::cout << ansi::red << "NotFound";
	std::cout << ansi::reset << std::endl;
}

int	main(void)
{
	const unsigned int		size = 10;
	std::array<int, size>	arr;
	for (unsigned int i = 0; i < size; i++)
		arr[i] = i;
	std::vector<int>		vec(arr.begin(), arr.end());
	std::deque<int>			deque(arr.begin(), arr.end());
	std::list<int>			list(arr.begin(), arr.end());

	srand(time(nullptr));
	while (!std::cin.eof())
	{
		std::cout << "Find" << '\n';
		easyTest(arr, rand() % (size * 2));
		easyTest(vec, rand() % (size * 2));
		easyTest(deque, rand() % (size * 2));
		easyTest(list, rand() % (size * 2));
		std::cin.get();
	}
}
