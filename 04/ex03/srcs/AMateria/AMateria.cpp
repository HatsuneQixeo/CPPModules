#include "AMateria.hpp"

AMateria::AMateria(const std::string &type):
	type(type)
{}

AMateria::AMateria(const AMateria &ref):
	type(ref.type)
{
	*this = ref;
}

AMateria	&AMateria::operator=(const AMateria &ref)
{
	/* Since Subject mentioned that copying the type doesn't make sense */
	// this->type = ref.type;
	return (*this);
	(void)ref;
}

AMateria::~AMateria(void)
{}

const std::string	&AMateria::getType(void) const
{
	return (this->type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* channels " << this->type
		<< " toward " << target.getName() << " *" << std::endl;
}
