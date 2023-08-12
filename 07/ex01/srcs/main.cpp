#include "iter.hpp"

int	main(void)
{
	typedef void	(*const TestFunc)(void);
	const TestFunc	test[] = {
		testInt,
		testString,
		testStrlist
	};
	const size_t	size = (sizeof(test) / sizeof(test[0]));

	for (size_t i = 0; i < size; i++)
		test[i]();
}
