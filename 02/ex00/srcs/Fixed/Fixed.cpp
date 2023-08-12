#include "Fixed.hpp"

Fixed::Fixed(void) : fixed(0)
{
	std::cout << "Fixed Default Constructor" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Fixed Copy Constructor" << std::endl;
	*this = ref;
}

Fixed	&Fixed::operator=(const Fixed &ref)
{
	std::cout << "Fixed Copy Assignment Operator" << std::endl;
	this->fixed = ref.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Fixed Destructor" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function" << std::endl;
	return (this->fixed);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function" << std::endl;
	this->fixed = raw;
}
