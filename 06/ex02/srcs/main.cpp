#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	Base				*arr[] = {
		new A(),
		new B(),
		new C(),
	};
	const unsigned int	size = (sizeof(arr) / sizeof(arr[0]));
	const unsigned int	ret = rand() % size;

	for (unsigned int i = 0; i < size; i++)
	{
		if (i != ret)
			delete arr[i];
	}
	return (arr[ret]);
}

void	identify(Base *p)
{
	std::cout << "Pointer Identifier  : ";
	if (dynamic_cast<A *>(p) != nullptr)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != nullptr)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != nullptr)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base &p)
{
	std::cout << "Reference Identifier: ";
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
}

int	main(void)
{
	srand(time(nullptr));
	while (std::cin.eof() == false)
	{
		Base	*obj = generate();

		obj->who();
		identify(obj);
		identify(*obj);
		delete obj;
		std::cin.get();
	}
	system("leaks -q identifier");
}
