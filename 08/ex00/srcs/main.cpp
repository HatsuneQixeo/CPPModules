#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include "easyfind.hpp"

template <typename T>
void	easyTest(T &container, const int find)
{
	typedef typename T::iterator	iterator;

	std::cout << "Searching for: " << find << " ...  ";
	iterator it_find = easyfind(container, find);
	if (it_find != container.end())
		std::cout << "Found in index: " << it_find - container.begin() << std::endl;
	else
		std::cout << "NotFound" << std::endl;
}

int	main(void)
{
	const unsigned int		size = 10;
	std::array<int, size>	arr;
	std::vector<int>		vec(size);
	std::deque<int>			deque(size);

	srand(time(nullptr));
	for (unsigned int i = 0; i < size; i++)
	{
		arr[i] = i;
		vec[i] = i;
		deque[i] = i;
	}
	while (!std::cin.eof())
	{
		easyTest(arr, (unsigned int)rand() % (size * 2));
		easyTest(vec, (unsigned int)rand() % (size * 2));
		easyTest(deque, (unsigned int)rand() % (size * 2));
		std::cin.get();
	}
}
