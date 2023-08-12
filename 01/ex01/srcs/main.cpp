#include "Zombie.hpp"

int	main(void)
{
	Zombie	*wave = zombieHorde(39, "zombiess");

	for (int i = 0; i < 39; i++)
	{
		std::cout << '[' << i << ']';
		wave[i].announce();
	}
	delete[] wave;
	system("leaks -q zombies");
}
