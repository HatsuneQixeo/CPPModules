#include "Cat.hpp"
#include "Dog.hpp"
#include <iomanip>

void	testSubject(void)
{
	std::cout << "Subject Test" << std::endl;
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();
	const Animal	*unknown = new Animal();

	delete dog;
	delete cat;
	delete unknown;
}

void	testArray(void)
{
	std::cout << "Animal Heaven Test" << std::endl;
	const unsigned int	size = 12;
	Animal 				*arr[size];

	for (unsigned int i = 0; i < size; i += 2)
		arr[i] = new Cat();
	for (unsigned int i = 1; i < size; i += 2)
		arr[i] = new Dog();
	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << "arr[" << std::setw(2) << i << "]: ";
		arr[i]->makeSound();
	}
	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << '\n' << "Destroying arr[" << i << "]" << std::endl;
		delete arr[i];
	}
}

/* Should only Copy the type because the Copy Assignment that get's called is animal's*/
void	testCopy(void)
{
	std::cout << "Biology Mutation Test" << std::endl;
	Animal	*cat = new Cat();
	Animal	*dog = new Dog();

	std::cout << '\n';
	std::cout << "Before Copy" << std::endl;
	cat->makeSound();
	*cat = *dog;
	std::cout << '\n';
	std::cout << "After Copy" << std::endl;
	cat->makeSound();

	std::cout << '\n';
	delete cat;
	delete dog;
}

void	testBrainCopy(void)
{
	std::cout << "Brain Surgery Test" << std::endl;
	Cat		cat;
	Dog		dog;
	Brain	*cat_brain = cat.getBrain();
	Brain	*dog_brain = dog.getBrain();

	std::cout << '\n';

	std::cout << "Cat Brain: " << std::endl;
	cat_brain->addIdea("Miku is cute", 39);
	cat.getBrain()->showIdeas();
	std::cout << '\n';

	*dog_brain = *cat_brain;
	std::cout << "Dog Brain After Copy: " << std::endl;
	dog.getBrain()->showIdeas();
	std::cout << std::endl;
}

/* Now I know what it meant by pointer is confusing */
template <typename A>
void	testDestructor(void)
{
	std::cout << ":)" << std::endl;
	A	animal;

	animal.makeSound();
	std::cout << '\n' << "First call to destrutor" << std::endl;
	animal.~A();

	animal.makeSound();
	std::cout << '\n' << "Second call to destructor" << std::endl;
	animal.~A();

	animal.makeSound();
	std::cout << '\n' << "Copy after call to destructor" << std::endl;
	animal = A();

	std::cout << '\n' << "Still there?" << std::endl;
	animal.makeSound();
}

int	main(void)
{
	typedef void	(*const ft_test)(void);
	const ft_test	arr[] = {
		testSubject,
		testArray,
		testCopy,
		testBrainCopy,
		testDestructor<Animal>,
		testDestructor<Cat>,
		testDestructor<Dog>,
	};
	const size_t	size = (sizeof(arr) / sizeof(arr[0]));

	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << "\033[2J";
		arr[i]();
		std::cin.get();
	}
	system("leaks -q brain");
}
