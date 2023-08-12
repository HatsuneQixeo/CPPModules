#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name):
	ClapTrap(name + "_clap_name"),
	name(name)
{
	std::cout << "DiamondTrap Default Constructor" << std::endl;
	this->type = "DiamondTrap";
	this->maxHP = FragTrap::HEALTH;
	this->hp = this->maxHP;
	this->ep = ScavTrap::ENERGY;
	this->atk = FragTrap::ATTACK;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref)
{
	std::cout << "DiamondTrap Copy Constructor" << std::endl;
	*this = ref;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &ref)
{
	std::cout << "DiamondTrap Copy Assignment Operator" << std::endl;
	this->name = ref.name;
	ClapTrap::operator=(ref);
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor" << std::endl;
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "I am " << *this << " and my name is " << this->name << std::endl;
}
