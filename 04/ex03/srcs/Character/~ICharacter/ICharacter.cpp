#include "ICharacter.hpp"

ICharacter::ICharacter(void)
{}

ICharacter::ICharacter(const ICharacter &ref)
{
	(void)ref;
}

ICharacter	&ICharacter::operator=(const ICharacter &ref)
{
	return (*this);
	(void)ref;
}

ICharacter::~ICharacter(void)
{}
