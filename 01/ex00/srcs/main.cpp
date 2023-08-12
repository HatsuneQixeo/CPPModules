#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie("common zombie");

	zombie.announce();
	randomChump("random zombie");
	Zombie	*dynamicZombie = newZombie("dynamic zombie");

	dynamicZombie->announce();
	delete dynamicZombie;
	system("leaks -q zombie");
}
