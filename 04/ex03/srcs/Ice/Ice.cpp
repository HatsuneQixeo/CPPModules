#include "Ice.hpp"

const std::string	Ice::TYPE_NAME = "ice";

Ice::Ice(void):
	AMateria(this->TYPE_NAME)
{}

Ice::Ice(const Ice &ref):
	AMateria(ref)
{
	*this = ref;
}

Ice	&Ice::operator=(const Ice &ref)
{
	AMateria::operator=(ref);
	return (*this);
}

Ice::~Ice(void)
{}

AMateria	*Ice::clone(void) const
{
	return (new Ice(*this));
}

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
