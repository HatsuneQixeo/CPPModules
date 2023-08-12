#include "Point.hpp"
#include <iomanip>

Point::Point(float x, float y): x(x), y(y)
{
	// std::cout << "Point Default Constructor" << std::endl;
}

Point::Point(const Point &ref): x(ref.x), y(ref.y)
{
	// std::cout << "Point Copy Constructor" << std::endl;
}

Point	&Point::operator=(const Point &ref)
{
	// std::cout << "Point Copy Assignment Operator" << std::endl;
	return (*this);
	(void)ref;
}

Point::~Point(void)
{
	// std::cout << "Point Destructor" << std::endl;
}

Fixed	Point::getX(void) const
{
	return (this->x);
}

Fixed	Point::getY(void) const
{
	return (this->y);
}

float	Point::areaSquare(const Point a, const Point b)
{
	const Fixed	area = (a.x - b.x) * (a.y - b.y);

	return (std::abs(area.toFloat()));
}

float	Point::areaTriangle(const Point a, const Point b, const Point c)
{
	const Fixed	abc = a.x * (b.y - c.y);
	const Fixed	bca = b.x * (c.y - a.y);
	const Fixed	cab = c.x * (a.y - b.y);

	return (std::abs(0.5 * (abc + bca + cab).toFloat()));
}

bool	Point::bsp(const Point a, const Point b, const Point c, const Point point)
{
	const float	areaABC = Point::areaTriangle(a, b, c);
	const float	areaPAB = Point::areaTriangle(point, a, b);
	const float	areaPBC = Point::areaTriangle(point, b, c);
	const float	areaPCA = Point::areaTriangle(point, c, a);

	return (areaPAB + areaPBC + areaPCA == areaABC
		&& areaPAB != 0 && areaPBC != 0 && areaPCA != 0);
}

std::ostream	&operator<<(std::ostream &stream, const Point &point)
{
	stream << "X:" << std::setw(4) << point.getX()
		<< ' '
		<< "Y:" << std::setw(4) << point.getY();
	return (stream);
}
