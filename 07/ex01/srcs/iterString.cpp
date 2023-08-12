#include "iter.hpp"

void	ft_toupper(char &c)
{
	c = toupper(c);
}

void	ft_tolower(char &c)
{
	c = tolower(c);
}

void	ft_capitalize(char &c)
{
	static bool	prevIsSpace = true;
	static char	*prevAddress = nullptr;

	c = ((prevIsSpace || prevAddress != (&c - 1)) ? toupper(c) : tolower(c));
	prevIsSpace = isspace(c);
	prevAddress = &c;
}

void	testString(void)
{
	typedef void	(*CharFunc)(char &c);

	char			str[] = "Hatsune Miku is cute";
	const size_t	size = strlen(str);
	const CharFunc	ft_log = show<char>;
	const CharFunc	callback[] = {
		ft_log,
		ft_toupper,
		ft_log,
		ft_tolower,
		ft_log,
		ft_capitalize,
		ft_log,
		ft_toupper,
		ft_log,
		ft_capitalize,
		ft_log,
	};
	const size_t	size_callback = (sizeof(callback) / sizeof(callback[0]));

	for (unsigned int i = 0; i < size_callback; i++)
	{
		std::cout << "Callback [" << i << "]" << std::endl;
		iter(str, size, callback[i]);
		std::cin.get();
	}
	std::cout << std::endl;
}
