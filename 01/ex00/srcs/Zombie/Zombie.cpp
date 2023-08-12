#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "Constructing zombie: " << name << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Destructing zombie: " << name << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiinnnzzzZ..." << std::endl;
}
