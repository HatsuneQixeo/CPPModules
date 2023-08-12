#include "Harl.hpp"

const Harl::ActionPair	Harl::actions[Harl::ACTION_COUNT] = {
	{.name = DEBUG, .func = &Harl::debug},
	{.name = INFO, .func = &Harl::info},
	{.name = WARNING, .func = &Harl::warning},
	{.name = ERROR, .func = &Harl::error}
};

Harl::Harl(void)
{
	std::cout << "Hi Harl" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Bye Harl" << std::endl;
}

void	Harl::debug(void) const
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger." << " "
		<< "I really do!" << std::endl;
}

void	Harl::info(void) const
{
	std::cout << "I cannot believe adding extra bacon costs more money." << " "
		<< "You didn’t put enough bacon in my burger!" << " "
		<< "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) const
{
	std::cout << "I think I deserve to have some extra bacon for free." << " "
		<< "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) const
{
	std::cout << "This is unacceptable!" << " "
		<< "I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) const 
{
	for (unsigned int i = 0; i < Harl::ACTION_COUNT; i++)
		if (actions[i].name == level)
			(this->*actions[i].func)();
}

int	Harl::filter_level(std::string level)
{
	unsigned int	i = 0;

	while (i < Harl::ACTION_COUNT && Harl::actions[i].name != level)
		i++;
	return (i);
}

void	Harl::filter(std::string level)
{
	switch (filter_level(level))
	{
		case (0):
			std::cout << "[ DEBUG ]" << '\n';
			this->debug();
		case (1):
			std::cout << "[ INFO ]" << '\n';
			this->info();
		case (2):
			std::cout << "[ WARNING ]" << '\n';
			this->warning();
		case (3):
			std::cout << "[ ERROR ]" << '\n';
			this->error();
			break ;
		default:
			std::cout << "[ Probaly complaining about insignificant problems ]" << std::endl;
	}
}
