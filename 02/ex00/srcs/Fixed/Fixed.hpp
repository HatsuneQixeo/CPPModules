#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					fixed;
		static const int	bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &ref);
		~Fixed(void);
		Fixed	&operator=(const Fixed &ref);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
};

#endif
