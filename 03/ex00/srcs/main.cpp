#include "ClapTrap.hpp"

#define	TARGET	"Target Practice"

void	testAfterlife(void)
{
	std::cout << "Dead test" << std::endl;
	ClapTrap	clapTrap;

	std::cout << '\n';
	/* Boom */
	clapTrap.showStatus();
	clapTrap.takeDamage(clapTrap.getHP() + 1);
	std::cout << '\n';
	/* Action after death */
	clapTrap.showStatus();
	clapTrap.attack(TARGET);
	std::cout << '\n';
	clapTrap.showStatus();
	clapTrap.beRepaired(39);
	std::cout << '\n';
	clapTrap.showStatus();
	clapTrap.takeDamage(39);
	std::cout << '\n';
}

void	testBasic(void)
{
	std::cout << "Basic test" << std::endl;
	ClapTrap	clapTrap;

	std::cout << '\n';
	/* Attacks */
	clapTrap.showStatus();
	clapTrap.attack(TARGET);
	std::cout << '\n';
	/* Takes damage */
	clapTrap.showStatus();
	clapTrap.takeDamage(5);
	std::cout << '\n';
	/* Repairs */
	clapTrap.showStatus();
	clapTrap.beRepaired(3);
	std::cout << '\n';
	clapTrap.showStatus();
	std::cout << '\n';
}

void	testRepairCap(void)
{
	std::cout << "Repair test" << std::endl;
	ClapTrap	clapTrap;

	std::cout << '\n';
	/* Repairing while having full health */
	clapTrap.showStatus();
	clapTrap.beRepaired(clapTrap.getHP());
	std::cout << '\n';
	/* Take damage */
	clapTrap.showStatus();
	clapTrap.takeDamage(clapTrap.getHP() / 2);
	std::cout << '\n';
	/* Repair after taking damage */
	clapTrap.showStatus();
	clapTrap.beRepaired(clapTrap.getHP() / 2);
	std::cout << '\n';
	clapTrap.showStatus();
	std::cout << '\n';
}

void	testNoEnergy(void)
{
	std::cout << "No Energy test" << std::endl;
	ClapTrap	clapTrap;

	std::cout << '\n';
	/* Consumes all ep */
	while (clapTrap.getEP())
	{
		clapTrap.showStatus();
		clapTrap.attack(TARGET);
		std::cout << '\n';
	}
	/* Tries to attack */
	clapTrap.showStatus();
	clapTrap.attack(TARGET);
	std::cout << '\n';
	/* Tries to repair */
	clapTrap.showStatus();
	clapTrap.beRepaired(39);
	std::cout << '\n';
	/* Takes damage like it should */
	clapTrap.showStatus();
	clapTrap.takeDamage(39);
	std::cout << '\n';
	clapTrap.showStatus();
	std::cout << '\n';
}

void	testCopy(void)
{
	std::cout << "Copy test" << std::endl;
	ClapTrap	clapTrap;

	std::cout << '\n';
	/* Change the initial status */
	clapTrap.showStatus();
	clapTrap.takeDamage(clapTrap.getHP() / 2);
	std::cout << '\n';
	clapTrap.showStatus();
	std::cout << '\n';
	/* Copy Constructor */
	ClapTrap(clapTrap).showStatus();
	std::cout << '\n';
	/* Copy assignment */
	ClapTrap	copyTrap("C0PY-TP");

	std::cout << '\n';
	copyTrap.showStatus();
	std::cout << '\n';
	copyTrap = clapTrap;
	std::cout << '\n';
	copyTrap.showStatus();
	std::cout << '\n';
}

void	genericTest(void)
{
	typedef void	(*ft_test)(void);
	const ft_test	test[] = {
		testBasic,
		testRepairCap,
		testNoEnergy,
		testAfterlife,
		testCopy,
	};

	for (unsigned int i = 0; i < (sizeof(test) / sizeof(test[0])); i++)
	{
		std::cout << "\033[2J";
		test[i]();
		std::cin.get();
	}
}

int	main(void)
{
	genericTest();
}
