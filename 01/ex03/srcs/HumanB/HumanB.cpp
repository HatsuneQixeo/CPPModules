#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
	std::cout << "Constructing HumanB: " << name << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "Destructing HumanB: " << name << std::endl;
}

void	HumanB::attack(void) const
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
