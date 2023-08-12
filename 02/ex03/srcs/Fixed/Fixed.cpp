#include "Fixed.hpp"

Fixed::Fixed(void) : fixed(0)
{
	// std::cout << "Fixed Default Constructor" << std::endl;
}

Fixed::Fixed(const int nbr): fixed(nbr * 0x100)
{
	// std::cout << "Fixed Int Constructor" << std::endl;
}

Fixed::Fixed(const float fnbr): fixed(std::roundf(fnbr * 0x100))
{
	// std::cout << "Fixed Float Constructor" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
	// std::cout << "Fixed Copy Constructor" << std::endl;
	*this = ref;
}

Fixed::~Fixed(void)
{
	// std::cout << "Fixed Destructor" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &ref)
{
	// std::cout << "Fixed Copy Assignment Operator" << std::endl;
	this->fixed = ref.fixed;
	return (*this);
}

/* Comparison operator */
bool	Fixed::operator==(const Fixed &ref) const
{
	return (!(*this != ref));
}

bool	Fixed::operator!=(const Fixed &ref) const
{
	return (*this < ref || *this > ref);
}

bool	Fixed::operator>(const Fixed &ref) const
{
	return (this->fixed > ref.fixed);
}

bool	Fixed::operator<(const Fixed &ref) const
{
	return (this->fixed < ref.fixed);
}

bool	Fixed::operator>=(const Fixed &ref) const
{
	return (!(*this < ref));
}

bool	Fixed::operator<=(const Fixed &ref) const
{
	return (!(*this > ref));
}

/* Arithmetic operator */
Fixed	Fixed::operator+(const Fixed &ref) const
{
	return (Fixed(this->toFloat() + ref.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &ref) const
{
	return (Fixed(this->toFloat() - ref.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &ref) const
{
	return (Fixed(this->toFloat() * ref.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &ref) const
{
	return (Fixed(this->toFloat() / ref.toFloat()));
}

/* Unary operator */
Fixed	&Fixed::operator++(void)
{
	++this->fixed;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	--this->fixed;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	this->fixed++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->fixed--;
	return (tmp);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixed / 0x100);
}

int	Fixed::toInt(void) const
{
	return (this->fixed / 0x100);
}

Fixed	&Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1 < ref2)
		return (ref2);
	else
		return (ref1);
}

Fixed	&Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1 > ref2)
		return (ref2);
	else
		return (ref1);
}

const Fixed	&Fixed::max(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1 < ref2)
		return (ref2);
	else
		return (ref1);
}

const Fixed	&Fixed::min(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1 > ref2)
		return (ref2);
	else
		return (ref1);
}

std::ostream	&operator<<(std::ostream &stream, const Fixed &ref)
{
	stream << ref.toFloat();
	return (stream);
}
