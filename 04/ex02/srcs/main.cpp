#include "Cat.hpp"
#include "Dog.hpp"
#include <iomanip>

void	testSubject(void)
{
	std::cout << "Subject Test" << std::endl;
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();
	/*
		Now that Animal is an abstract class,
		it cannot be instantiate as an object anymore
	*/
	// const Animal	*unknown = new Animal();

	delete dog;
	delete cat;
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
		// testDestructor<Animal>,
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
	system("leaks -q abstract");
	system("leaks -q brain");
}

/* Reason for using abstract class

Abstract class is a class with at least one missing definition for their member function,
where the member function does not have any definition for the class on it's own.

The use of abstract class usually signify that there is no logical implementation for the class itself,
where the function definition is instead defined in the derived class.

It's something like:
	I need this member function for myself,
	but I have no idea how the function is executed.


Enough with the concept that is not explaining anything,
let's start by showing the flaws of non abstract class in a specific case.

By default, this is how a member function is declared like
	void	ftname(void);
with a function definition somewhere.


If I add a virtual keyword to the beginning of the function prototype:
	virtual	void	ftname(void);
Now, whenever ftname is called,
it will instead call the function in the derived class by default,
(if there is an implementation of it in the derived class),
regardless of the type of the pointer.


Here's the problem, what if there's no logical implementation for the member function,
yet the member function still need to declared at the base class for polymorphism purpose?

Let's see what I mean by that in the example provided below:
*/

/* Non abstract base class

This is a class called Shape,
it is a base class for any class that is meant to represent a 2d shape.

It has:
* private member variable for representing the type of the shape, where will be given by the derived class.

* a member function for returning the type
* a member function for returning the area of the shape
*/

// class Shape
// {
// 	private:
// 		std::string	type;
// 	public:
// 		Shape(const std::string &type):
// 			type(type)
// 		{}
// 		virtual ~Shape(void)
// 		{}
// 		std::string	getType(void) const
// 		{
// 			return (this->type);
// 		}
// 		/*
// 			You see, this class does not actually know what shape it's gonna be,
// 			and without knowing that, how is it possible to even calculate the area?
// 			With each shape having their own formula for themselves?
// 		*/
// 		virtual float	getArea(void) const
// 		{
// 			return (-1);
// 		}
// };

// /*
// Let's actually implement an actual shape to better illustrate what I mean
// */

// class Square: public Shape
// {
// 	private:
// 		float	length;
// 	public:
// 		Square(float length):
// 			Shape("Square"),
// 			length(length)
// 		{}
// 		float	getArea(void) const
// 		{
// 			return (this->length * this->length);
// 		}
// };

// class ShapeOfYou: public Shape
// {
// 	private:
// 	public:
// 		ShapeOfYou(void):
// 			Shape("ShapeOfYou")
// 		{}
// /* Oh no! I forgot to implement the function for getArea what a dumbass I am! */
// };


// int	main(void)
// {
// 	{
// 		const Shape	*square = new Square(10);
// 		const Shape	*yourShape = new ShapeOfYou();
// 		const Shape	*unknown = new Shape("Unknown");

// 		std::cout << square->getType() << " has an area of: " << square->getArea() << std::endl;
// 		std::cout << yourShape->getType() << " has an area of: " << yourShape->getArea() << std::endl;
// 		std::cout << unknown->getType() << " has an area of: " << unknown->getArea() << std::endl;
// 		delete square;
// 		delete yourShape;
// 		delete unknown;
// 	}
// 	system("leaks -q abstract");
// }





/* As you could see, it takes a compilation like no problem, that's NOT a great code right there.

Not only it will not generate compile error if the derived class is missing an implementation for getArea,
which will caused unexpected behaviours later needs to be debug,
the base class could also be instantiate as an.. UnknownShape?
Which doesn't really makes sense on it's own.


Of course I could make it throw error,
but that will happen only when I try to call the missing function,
and there'a a better way than that.

A way where you can tell the compiler what you're trying to do,
and have it generate compile error if you're being forgetful,
preventing the problem before you even need to run the program.


To do that, just add a (= 0) at the back of the function prototype:
	virtual float	getArea(void) const = 0;

This is what called: ${BOLD}${PURE}${SHINY}${GOLD} Pure virtual member function ${RESET}

By declaring the member function as pure virtual,
you're stating that this function does not has any definition in the given class,
instead you have to implement the function in the derived class.

With that, the class is now officially an abstract class.
*/

// class Shape
// {
// 	private:
// 		std::string	type;
// 	public:
// 		Shape(const std::string &type): type(type)
// 		{}
// 		virtual ~Shape(void)
// 		{}
// 		std::string		getType(void) const
// 		{
// 			return (this->type);
// 		}
// 		virtual float	getArea(void) const = 0;
// };

// class Square: public Shape
// {
// 	private:
// 		float	length;
// 	public:
// 		Square(float length):
// 			Shape("Square"),
// 			length(length)
// 		{}
// 		float	getArea(void) const
// 		{
// 			return (this->length * this->length);
// 		}
// };

// class ShapeOfYou: public Shape
// {
// 	private:
// 	public:
// 		ShapeOfYou(void):
// 			Shape("ShapeOfYou")
// 		{}
// /* Oh no! I forgot to implement the function for getArea what a dumbass I am! */
// };

// class Rectangle: public Shape
// {
// 	private:
// 		float	length;
// 		float	width;
// 	public:
// 		Rectangle(float length, float width):
// 			Shape("Rectangle"),
// 			length(length),
// 			width(width)
// 		{}

// 		/* For Rectangle, it's just a simple (length * width) */
// 		float	getArea(void) const
// 		{
// 			return (this->length * this->width);
// 		}
// };

// class Triangle: public Shape
// {
// 	private:
// 		float	base;
// 		float	height;
// 	public:
// 		Triangle(float base, float height):
// 			Shape("Triangle"),
// 			base(base),
// 			height(height)
// 		{}

// 		/* For Triangle, (base * height) needs to be divided by half */
// 		float	getArea(void) const
// 		{
// 			return (0.5 * (this->base * this->height));
// 		}
// };

// class Circle: public Shape
// {
// 	private:
// 		float	radius;
// 	public:
// 		Circle(float radius):
// 			Shape("Circle"),
// 			radius(radius)
// 		{}

// 		/* For Circle, the formula includes the use of pie and even using only one variable */
// 		float	getArea(void) const
// 		{
// 			return (3.14 * (this->radius * this->radius));
// 		}
// };

// int	main(void)
// {
// 	/* Now the base class cannot be instantiate on it's own anymore */
// 	// Shape	*shape = new Shape("Unknown");
// 	/* Neither can the derived class without a concrete definition for it */
// 	// Shape	*nuhUh = new ShapeOfYou();
// 	{
// 		const Shape		*shapes[] = {
// 			new Square(10),
// 			new Rectangle(10, 5),
// 			new Triangle(10, 5),
// 			new Circle(7),
// 		};
// 		const size_t	size = (sizeof(shapes) / sizeof(shapes[0]));

// 		for (unsigned int i = 0; i < size; i++)
// 			std::cout << "shapes[" << i << "]: " << shapes[i]->getType()
// 				<< " has an area of " << shapes[i]->getArea() << std::endl;
// 		for (unsigned int i = 0; i < size; i++)
// 			delete shapes[i];
// 	}
// 	system("leaks -q abstract");
// }

/*
Some alternative use for abstract class is to make a contract for the derived class,
a contract where the derived class promise to implement the member function for themselves.

The contract is usually made for letting the derived class has their own exclusive definition of the member function,
and making sure that is it actually implemented somewhere,
where the compiler would generate error if the derived class is instantiate with missing function definition like mentioned.

This reason also intensifies the idea of having an abstract base class,
rather than implementing every shape as their own individual class.
*/
