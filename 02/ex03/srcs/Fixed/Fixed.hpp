#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					fixed;
		static const int	bits = 8;

	public:
		Fixed(void);
		Fixed(const int nbr);
		Fixed(const float fnbr);
		Fixed(const Fixed &ref);
		~Fixed(void);

		Fixed	&operator=(const Fixed &ref);

		/* Comparison operator */
		bool	operator==(const Fixed &ref) const;
		bool	operator!=(const Fixed &ref) const;
		bool	operator>(const Fixed &ref) const;
		bool	operator<(const Fixed &ref) const;
		bool	operator>=(const Fixed &ref) const;
		bool	operator<=(const Fixed &ref) const;

		/* Arithmetic operator */
		Fixed	operator+(const Fixed &ref) const;
		Fixed	operator-(const Fixed &ref) const;
		Fixed	operator*(const Fixed &ref) const;
		Fixed	operator/(const Fixed &ref) const;

		/* PreUnary operator */
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		/* PostUnary operator */
		Fixed	operator++(int);
		Fixed	operator--(int);

		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed		&max(Fixed &ref1, Fixed &ref2);
		static Fixed		&min(Fixed &ref1, Fixed &ref2);
		static const Fixed	&max(const Fixed &ref1, const Fixed &ref2);
		static const Fixed	&min(const Fixed &ref1, const Fixed &ref2);
};

std::ostream	&operator<<(std::ostream &stream, const Fixed &ref);
#endif
