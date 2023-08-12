#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	std::cout << "Constructing HumanA: " << name << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "Destructing HumanA: " << name << std::endl;
}

void	HumanA::attack(void) const
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
