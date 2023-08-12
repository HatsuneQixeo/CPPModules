#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
	std::cout << "Constructing Weapon: " << type << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Destructing Weapon: " << type << std::endl;
}

const std::string	&Weapon::getType(void) const
{
	return (this->type);
}

void	Weapon::setType(std::string newType)
{
	this->type = newType;
}
