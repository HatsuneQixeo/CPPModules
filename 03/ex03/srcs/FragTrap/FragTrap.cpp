#include "FragTrap.hpp"
#include <unistd.h>

FragTrap::FragTrap(const std::string &name):
	ClapTrap(name)
{
	std::cout << "FragTrap Default Constructor" << std::endl;
	this->type = "FragTrap";
	this->maxHP = this->HEALTH;
	this->hp = this->maxHP;
	this->ep = this->ENERGY;
	this->atk = this->ATTACK;
}

FragTrap::FragTrap(const FragTrap &ref)
{
	std::cout << "FragTrap Copy Constructor" << std::endl;
	*this = ref;
}

FragTrap	&FragTrap::operator=(const FragTrap &ref)
{
	std::cout << "FragTrap Copy Assignment Operator" << std::endl;
	ClapTrap::operator=(ref);
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	const char	*highFive = "✋";
	std::string	input;

	std::cout << *this << " is asking for a " << highFive << std::endl;
	if (!this->isalive())
		std::cout << *this << " is already dead" << std::endl;
	else if (this->ep <= 1)
		std::cout << *this << (this->ep ? " does not have enough" : " ran out of") << " energy" << std::endl;
	else
	{
		std::cout << "High five? (paste " << highFive << " if yes)> ";
		getline(std::cin, input);
		this->atk += std::min<int>(this->atk * .15, UINT16_MAX - this->atk);
		std::cout << *this << " gets increase damage" << std::endl;
		this->beRepaired(this->maxHP * .30);
		if (input == highFive)
		{
			std::cout << "(*´ω`)人(´ω`*)" << std::endl;
			sleep(1);
			this->atk += std::min<int>(this->atk * .50, UINT16_MAX - this->atk);
			std::cout << *this << " gets increase fire rate" << std::endl;
		}
		else
			std::cout << "screw you guys!" << std::endl;
		this->ep--;
	}
}
