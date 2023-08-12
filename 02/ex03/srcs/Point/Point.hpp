#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point(float x = 0, float y = 0);
		Point(const Point &ref);
		~Point(void);
		Point	&operator=(const Point &ref);

		Fixed	getX(void) const;
		Fixed	getY(void) const;

		static float	areaTriangle(const Point a, const Point b, const Point c);
		static float	areaSquare(const Point a, const Point b);
		static bool		bsp(const Point a, const Point b, const Point c, const Point point);
};

std::ostream	&operator<<(std::ostream &stream, const Point &point);

#endif
