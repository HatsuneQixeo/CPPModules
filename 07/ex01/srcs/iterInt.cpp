#include "iter.hpp"

void	increment(int &ele)
{
	ele++;
}

void	decrement(int &ele)
{
	ele--;
}

void	testInt(void)
{
	typedef void	(*IntFunc)(int &n);

	int				arr[] = {1, 2, 3, 4, 5};
	const size_t	size = sizeof(arr) / sizeof(arr[0]);
	const IntFunc	ft_log = showBrace<int>;
	const IntFunc	callback[] = {
		ft_log,
		increment,
		ft_log,
		decrement,
		ft_log,
	};
	const size_t	size_callback = (sizeof(callback) / sizeof(callback[0]));

	for (unsigned int i = 0; i < size_callback; i++)
	{
		std::cout << "Callback [" << i << "]" << std::endl;
		iter(arr, size, callback[i]);
		std::cin.get();
	}
	std::cout << std::endl;
}
