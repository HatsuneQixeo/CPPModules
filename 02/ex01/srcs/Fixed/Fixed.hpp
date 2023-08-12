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

		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &stream, const Fixed &ref);
#endif
