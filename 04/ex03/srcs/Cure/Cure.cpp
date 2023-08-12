#include "Cure.hpp"

const std::string	Cure::TYPE_NAME = "cure";

Cure::Cure(void):
	AMateria(this->TYPE_NAME)
{}

Cure::Cure(const Cure &ref):
	AMateria(this->TYPE_NAME)
{
	*this = ref;
}

Cure	&Cure::operator=(const Cure &ref)
{
	AMateria::operator=(ref);
	return (*this);
}

Cure::~Cure(void)
{}

AMateria	*Cure::clone(void) const
{
	return (new Cure(*this));
}

void		Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
