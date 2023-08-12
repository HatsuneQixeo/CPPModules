#include "Fixed.hpp"

Fixed::Fixed(void) : fixed(0)
{
	std::cout << "Fixed Default Constructor" << std::endl;
}

Fixed::Fixed(const int nbr): fixed(nbr * 0x100)
{
	std::cout << "Fixed Int Constructor" << std::endl;
}

Fixed::Fixed(const float fnbr): fixed(std::roundf(fnbr * 0x100))
{
	std::cout << "Fixed Float Constructor" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Fixed Copy Constructor" << std::endl;
	*this = ref;
}

Fixed::~Fixed(void)
{
	std::cout << "Fixed Destructor" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &ref)
{
	std::cout << "Fixed Copy Assignment Operator" << std::endl;
	this->fixed = ref.fixed;
	return (*this);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixed / 0x100);
}

int	Fixed::toInt(void) const
{
	return (this->fixed / 0x100);
}

std::ostream	&operator<<(std::ostream &stream, const Fixed &ref)
{
	stream << ref.toFloat();
	return (stream);
}
