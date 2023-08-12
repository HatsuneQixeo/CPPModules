#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#define	TARGET	"Target Practice"

template<typename T>
void	testAfterlife(void)
{
	std::cout << "Dead test" << std::endl;
	T	clapTrap;

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

template<typename T>
void	testBasic(void)
{
	std::cout << "Basic test" << std::endl;
	T	clapTrap;

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

template<typename T>
void	testRepairCap(void)
{
	std::cout << "Repair test" << std::endl;
	T	clapTrap;

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

template<typename T>
void	testNoEnergy(void)
{
	std::cout << "No Energy test" << std::endl;
	T	clapTrap;

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

template<typename T>
void	testCopy(void)
{
	std::cout << "Copy test" << std::endl;
	T	clapTrap;

	std::cout << '\n';
	/* Change the initial status */
	clapTrap.showStatus();
	clapTrap.takeDamage(clapTrap.getHP() / 2);
	std::cout << '\n';
	clapTrap.showStatus();
	std::cout << '\n';
	/* Copy Constructor */
	T(clapTrap).showStatus();
	std::cout << '\n';
	/* Copy assignment */
	T	copyTrap("C0PY-TP");

	std::cout << '\n';
	copyTrap.showStatus();
	std::cout << '\n';
	copyTrap = clapTrap;
	std::cout << '\n';
	copyTrap.showStatus();
	std::cout << '\n';
}

template<typename T>
void	genericTest(void)
{
	typedef void	(*ft_test)(void);
	const ft_test	test[] = {
		testBasic<T>,
		testRepairCap<T>,
		testNoEnergy<T>,
		testAfterlife<T>,
		testCopy<T>,
	};

	for (unsigned int i = 0; i < (sizeof(test) / sizeof(test[0])); i++)
	{
		std::cout << "\033[2J";
		test[i]();
		std::cin.get();
	}
}

template<typename T>
void	testScav(void)
{
	std::cout << "ScavTrap guardGate test" << std::endl;
	T	scav;

	std::cout << '\n';
	scav.showStatus();
	scav.guardGate();
	std::cout << '\n';
	scav.showStatus();
	scav.beRepaired(39);
	std::cout << '\n';
	scav.showStatus();
	scav.takeDamage(scav.getHP() - 1);
	std::cout << '\n';
	scav.showStatus();
	scav.guardGate();
	std::cout << '\n';
	scav = T("R3::SC4V-TP V2");
	std::cout << '\n';
	while (scav.getEP())
	{
		scav.showStatus();
		scav.guardGate();
		std::cout << '\n';
	}
	scav.showStatus();
	scav.guardGate();
	std::cout << '\n';
}

template<typename T>
void	testFrag(void)
{
	std::cout << "FragTrap highFiveGuys test" << std::endl;
	T	frag;

	std::cout << '\n';
	while (frag.getEP())
	{
		frag.showStatus();
		frag.highFivesGuys();
		std::cout << '\n';
	}
	frag.showStatus();
	frag.highFivesGuys();
	std::cout << '\n';
}

void	testDiamond(void)
{
	std::cout << "DiamondTrap test" << std::endl;
	DiamondTrap	diamond;
	DiamondTrap	copyDia("C0PY-D14-TP");

	std::cout << '\n';
	diamond.whoAmI();
	diamond.showStatus();
	std::cout << '\n';

	copyDia.whoAmI();
	copyDia.showStatus();
	std::cout << '\n';
	copyDia = diamond;
	std::cout << '\n';
	copyDia.whoAmI();
	copyDia.showStatus();
	std::cout << '\n';
	DiamondTrap	copycopy(copyDia);

	std::cout << '\n';
	copycopy.whoAmI();
	copycopy.showStatus();
	std::cout << '\n';
}

int	main(void)
{
	genericTest<DiamondTrap>();
	testFrag<DiamondTrap>();
	std::cout << "\n";
	testScav<DiamondTrap>();
	std::cout << "\n";
	testDiamond();
}
