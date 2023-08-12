#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	subjectTest(void)
{
	std::cout << "SUBJECT TEST" << std::endl;
	const Animal	*meta = new Animal();
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();

	std::cout << '\n' << "Type" << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << '\n' << "MakeSound" << std::endl;
	meta->makeSound();
	dog->makeSound();
	cat->makeSound();
	/* Can still call the function in the base class explicitly */
	// dog->Animal::makeSound();
	delete meta;
	delete dog;
	delete cat;
}

void	wrongTest(void)
{
	std::cout << "WRONG TEST" << std::endl;
	const	WrongAnimal	*wmeta = new WrongAnimal();
	const	WrongAnimal	*wcat = new WrongCat();

	std::cout << '\n' << "MakeSound" << std::endl;
	wmeta->makeSound();
	wcat->makeSound();
	/* Wrong meows lel */
	// ((const WrongCat *)wmeta)->makeSound();
	// ((const WrongCat *)wcat)->makeSound();

	/* Wrong unknown sound */
	// ((const WrongCat *)wcat)->WrongAnimal::makeSound();
	delete wmeta;
	delete wcat;
}

int	main(void)
{
	subjectTest();
	std::cin.get();
	wrongTest();
	system("leaks -q polymorphism");
}

/* Things with polymorphism
Some common use I have seen in future project so far for polymorphism is to
group multiple types of derived classes together inside an array as their common base class,
the array then could be used for searching a matching class, and return a pointer to the object,
and/or have a common base class for the functions return type that could return different types of derived class.

Although allocating an array of objects just to delete the all of them,
other than the one matching value, that might or might not be there,
is rather wasteful for performance,
it more or less compensated for the modularity.

To be honest, I'd much prefer a chain of if and elif just to avoid all the memory allocation that is required by declaring an array of pointers,
can't quite imagine the performance if I can't perform a binary search on top of the array.

Even if I could perform a binary search, is it worth it since I have to sort the array too?
	(Sort it manually in the source code let's go!)
*/
