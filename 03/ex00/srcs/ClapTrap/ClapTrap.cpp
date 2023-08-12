#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name):
	type("ClapTrap"),
	maxHP(10),
	name(name),
	hp(this->maxHP),
	ep(10),
	atk(0)
{
	std::cout << "ClapTrap Default Constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ref)
{
	std::cout << "ClapTrap Copy Constructor" << std::endl;
	*this = ref;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &ref)
{
	std::cout << "ClapTrap Copy Assignment Operator" << std::endl;
	this->type = ref.type;
	this->name = ref.name;
	this->maxHP = ref.maxHP;
	this->hp = ref.hp;
	this->ep = ref.ep;
	this->atk = ref.atk;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	std::cout << *this << " is trying to attack " << target << std::endl;
	if (!this->isalive())
		std::cout << *this << " is already dead" << std::endl;
	else if (this->ep == 0)
		std::cout << *this << " ran out of energy!" << std::endl;
	else
	{
		std::cout << *this << " attacks " << target
			<< " dealing " << this->atk << " damage!" << std::endl;
		this->ep--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << *this << " is taking " << amount << " damage" << std::endl;
	if (!this->isalive())
		std::cout << *this << " (stop he's already dead)" << std::endl;
	else if (amount >= this->hp)
		std::cout << *this << " took a lethal blow of " << amount << " damage!" << std::endl;
	else
		std::cout << *this << " took " << amount << " damage!" << std::endl;
	this->hp -= std::min(amount, this->hp);
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << *this << " is trying to repair " << amount << " hp " << std::endl;
	if (!this->isalive())
		std::cout << *this << " is beyond repair!" << std::endl;
	else if (this->ep == 0)
		std::cout << *this << " ran out of energy!" << std::endl;
	else
	{
		amount = std::min(amount, this->maxHP - this->hp);
		this->hp += amount;
		std::cout << *this << " repaired " << amount << " hp" << std::endl;
		this->ep--;
	}
}

bool	ClapTrap::isalive(void) const
{
	return (this->hp != 0);
}

void	ClapTrap::showStatus(void) const
{
	const char	*colour;

	if (this->hp <= this->maxHP / 4)
		colour = ANSI_RED;
	else if (this->hp <= this->maxHP / 2)
		colour = ANSI_YELLOW;
	else
		colour = ANSI_GREEN;
	std::cout << *this << ' '
		<< colour << "HP: " << this->hp << "/" << this->maxHP << ' '
		<< ANSI_BLUE"EP: " << this->ep << ' '
		<< ANSI_CYAN"ATK: " << this->atk << ANSI_RESET << std::endl;
}

std::string	ClapTrap::getType(void) const
{
	return (this->type);
}

std::string	ClapTrap::getName(void) const
{
	return (this->name);
}

unsigned int	ClapTrap::getHP(void) const
{
	return (this->hp);
}

unsigned int	ClapTrap::getEP(void) const
{
	return (this->ep);
}

int	ClapTrap::getAtk(void) const
{
	return (this->atk);
}

std::ostream	&operator<<(std::ostream &stream, const ClapTrap &ref)
{
	stream << "[" << ref.getType() << "] " << ref.getName();
	return (stream);
}
