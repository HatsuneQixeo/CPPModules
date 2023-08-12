#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat Default Constructor" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &ref):
	WrongAnimal(ref)
{
	std::cout << "WrongCat Copy Constructor" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &ref)
{
	std::cout << "WrongCat Copy Assignment Operator" << std::endl;
	WrongAnimal::operator=(ref);
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << this->getType() << ": Wrong meows" << std::endl;
}
