#include "Fixed.hpp"
#include <iomanip>

#define INT24_MAX	0x7fffff
#define INT24_MIN	0x800000
#define UINT24_MAX	0xffffff

void	showBytes(void)
{
	for (unsigned int i = 1; i != 0; i++)
	{
		std::cout << "Value : " << i << std::endl;
		// std::cout << "Hexa  : " << std::setw(8) << std::hex << i << std::dec << std::endl;
		{
			unsigned char	*ptr = (unsigned char *)&i;

			std::cout << "Memory: ";
			for (unsigned int j = 0; j < sizeof(i); j++)
				std::cout << '[' << std::setw(3) << (int)ptr[j] << ']';
			std::cout << '\n' << '\n';
		}
		if ((unsigned int)i % 256 == 0)
			std::cin.get();
	}
}

int	main(void)
{
	Fixed		a;
	const Fixed	b(10);
	const Fixed	c(42.42f);
	const Fixed	d(b);
	// const Fixed	max(INT24_MAX);
	// const Fixed	min(INT24_MIN);

	a = Fixed(1234.4321f);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	// std::cout << "max " << max << std::endl;
	// std::cout << "min " << min << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	// std::cout << "max " << max.toInt() << " as integer" << std::endl;
	// std::cout << "min " << min.toInt() << " as integer" << std::endl;
}
