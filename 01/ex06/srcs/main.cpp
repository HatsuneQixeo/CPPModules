#include "Harl.hpp"

int	main(int argc, const char **argv)
{
	if (argc == 1)
		Harl().filter("Hatsune Miku is cute");
	else
		Harl().filter(argv[1]);
}
