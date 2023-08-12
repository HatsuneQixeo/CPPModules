#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

void	testMateria(void)
{
	std::cout << "MATERIA TEST" << std::endl;
	AMateria	*ice = new Ice();
	AMateria	*cure = new Cure();
	AMateria	*copyIce = new Ice(Ice());
	AMateria	*copyCure = new Cure(Cure());

	std::cout << "ice     : " << ice->getType() << std::endl;
	std::cout << "cure    : " << cure->getType() << std::endl;
	std::cout << "copyIce : " << copyIce->getType() << std::endl;
	std::cout << "copyCure: " << copyCure->getType() << std::endl;
	*copyIce = *copyCure;
	std::cout << "copyIce after copy assignment: " << copyIce->getType() << std::endl;
	delete ice;
	delete cure;
	delete copyIce;
	delete copyCure;
}

void	testInventory(void)
{
	std::cout << "INVENTORY TEST" << std::endl;
	ICharacter	*character = new Character("Barret");
	AMateria	*overflow = new Cure();

	for (unsigned int i = 0; i < Character::INVENTORY_SIZE; i++)
		character->equip(new Cure());
	character->equip(overflow);

	std::cout << "Equip after unequip" << std::endl;
	{
		delete character->unequip(0);
		character->equip(new Cure());
		character->equip(overflow);
	}
	std::cout << '\n';
	std::cout << "Use before delete" << std::endl;
	{
		for (unsigned int i = 0; i < Character::INVENTORY_SIZE; i++)
			character->use(i, *character);
	}
	std::cout << '\n';
	std::cout << "Clear inventory" << std::endl;
	{
		for (unsigned int i = 0; i < Character::INVENTORY_SIZE; i++)
			delete character->unequip(i);
	}
	std::cout << '\n';
	std::cout << "Use after cleared inventory" << std::endl;
	{
		for (unsigned int i = 0; i < Character::INVENTORY_SIZE; i++)
			character->use(i, *character);
	}
	std::cout << '\n';
	std::cout << "2nd Clear" << std::endl;
	{
		for (unsigned int i = 0; i < Character::INVENTORY_SIZE; i++)
			delete character->unequip(i);
	}
	std::cout << '\n';
	delete overflow;
	delete character;
}

void	testMix(void)
{
	std::cout << "MIX TEST" << std::endl;
	IMateriaSource	*materiaFactory = new MateriaSource();

	materiaFactory->learnMateria(new Ice());
	std::cout << "Create cure before learning cure: "
		<< materiaFactory->createMateria(Cure::TYPE_NAME) << std::endl;
	materiaFactory->learnMateria(new Cure());
	std::cout << "Create Unknown materia: "
		<< materiaFactory->createMateria("miku") << std::endl;

	ICharacter		*cloud = new Character("Cloud");
	{
		cloud->equip(materiaFactory->createMateria(Ice::TYPE_NAME));
	}

	ICharacter		*aerith = new Character("Aerith");
	{
		aerith->equip(materiaFactory->createMateria(Cure::TYPE_NAME));
	}

	ICharacter		*sephiroth = new Character("Sephiroth");
	{
		sephiroth->equip(materiaFactory->createMateria(Ice::TYPE_NAME));
		sephiroth->equip(materiaFactory->createMateria(Cure::TYPE_NAME));
	}

	sephiroth->use(0, *cloud);
	cloud->use(0, *sephiroth);
	aerith->use(0, *cloud);
	sephiroth->use(1, *sephiroth);
	std::cout << '\n';

	delete materiaFactory;
	delete cloud;
	delete aerith;
	delete sephiroth;
}

void	testSubject(void)
{
	std::cout << "SUBJECT TEST" << std::endl;
	IMateriaSource	*src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter	*me = new Character("me");
	AMateria	*tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter	*bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	std::cout << '\n';
}

int	main(void)
{
	typedef void	(*const ft_test)(void);
	const ft_test	arr[] = {
		testSubject,
		testInventory,
		testMateria,
		testMix,
	};
	const size_t	size = (sizeof(arr) / sizeof(arr[0]));
	
	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << "\033[2J";
		arr[i]();
		std::cin.get();
	}
	system("leaks -q interface");
}
