#include "Point.hpp"

void	testbsp(const Point a, const Point b, const Point c, const Point point)
{
	std::cout 
		<< "a    : " << a << '\n'
		<< "b    : " << b << '\n'
		<< "c    : " << c << '\n'
		<< "point: " << point << '\n'
		<< Point::bsp(a, b , c, point) << '\n'
		<< std::endl;
}

int	main(void)
{
	std::cout << std::boolalpha;
	testbsp(Point(0, 0), Point(0, 10), Point(10, 5), Point(0, 0));
	testbsp(Point(0, 0), Point(0, 10), Point(10, 5), Point(0, 5));
	testbsp(Point(0, 0), Point(5, 10), Point(10, 5), Point(1, 1));
	testbsp(Point(2.923, 1.112), Point(10, 10), Point(10.1, 0), Point(8.1, 2.5));
}
