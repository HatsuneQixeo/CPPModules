#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name):
	ClapTrap(name)
{
	std::cout << "ScavTrap Default Constructor" << std::endl;
	this->type = "ScavTrap";
	this->maxHP = this->HEALTH;
	this->hp = this->maxHP;
	this->ep = this->ENERGY;
	this->atk = this->ATTACK;
}

ScavTrap::ScavTrap(const ScavTrap &ref)
{
	std::cout << "ScavTrap Copy Constructor" << std::endl;
	*this = ref;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &ref)
{
	std::cout << "ScavTrap Copy Assignment Operator" << std::endl;
	ClapTrap::operator=(ref);
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	std::cout << *this << " is trying to launch an attack on " << target << std::endl;
	if (!this->isalive())
		std::cout << *this << " is already dead" << std::endl;
	else if (this->ep == 0)
		std::cout << *this << " ran out of energy!" << std::endl;
	else
	{
		if ((unsigned int)rand() % 100 < 80)
			std::cout << *this << " lands it's attacks on " << target
				<< " dealing " << this->atk << " damage!" << std::endl;
		else
			std::cout << *this << " missed the attacks!" << std::endl;
		this->ep--;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << *this << " is trying to enter guard gate mode" << std::endl;
	if (!this->isalive())
		std::cout << *this << " is already dead" << std::endl;
	else if (this->ep == 0)
		std::cout << *this << " ran out of energy!" << std::endl;
	else
	{
		std::cout << *this << " enters guard gate mode" << std::endl;
		std::cout << *this << " increased it's max hp" << std::endl;
		this->maxHP += 10;
		this->ep--;
	}
}
