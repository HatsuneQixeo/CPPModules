#include "Fixed.hpp"
#include <iomanip>

template <typename OP>
void	test(const std::string &name, OP operation)
{
	const Fixed		arr[] = {
		Fixed(39),
		Fixed(831),
		Fixed(3.9f + 0.001f),
		Fixed(8.31f + 0.001f),
	};
	const size_t	size = (sizeof(arr) / sizeof(arr[0]));

	std::cout << std::left;
	for (unsigned int primary = 0; primary < size; primary++)
	{
		for (unsigned int secondary = 0; secondary < size; secondary++)
		{
			std::cout << std::setw(8) << arr[primary]
				<< ' ' << name << ' '
				<< std::setw(8) << arr[secondary]
				<< " = " << (arr[primary].*operation)(arr[secondary]) << '\n';
		}
		std::cout << '\n';
	}
	std::cout << std::right << std::endl;
}

void	testCompare(void)
{
	std::cout << std::boolalpha;
	test("==", &Fixed::operator==);
	test("!=", &Fixed::operator!=);
	test(">", &Fixed::operator>);
	test("<", &Fixed::operator<);
	test(">=", &Fixed::operator>=);
	test("<=", &Fixed::operator<=);
}

void	testArith(void)
{
	test("+", &Fixed::operator+);
	test("-", &Fixed::operator-);
	test("*", &Fixed::operator*);
	test("/", &Fixed::operator/);
}

void	testUnary(void)
{
	Fixed	a;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
}

void	testMaxMin(void)
{
	Fixed		a(.39f);
	const Fixed	b(Fixed(5.05f) * Fixed(2));
	Fixed		c(8.31f);
	Fixed		d(39);

	std::cout << "a  : " << a << std::endl;
	std::cout << "b  : " << b << std::endl;
	std::cout << "Max: " << Fixed::max(a, b) << std::endl;
	std::cout << "Min: " << Fixed::min(a, b) << std::endl;
	std::cout << '\n';
	std::cout << "c  : " << c << std::endl;
	std::cout << "d  : " << d << std::endl;
	std::cout << "Max: " << Fixed::max(c, d) << std::endl;
	std::cout << "Min: " << Fixed::min(c, d) << std::endl;
}

int	main(void)
{
	testCompare();
	testArith();
	testUnary();
	testMaxMin();
}
