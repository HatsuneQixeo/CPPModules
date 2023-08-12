#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat Default Constructor" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &ref)
{
	std::cout << "Cat Copy Constructor" << std::endl;
	*this = ref;
}

Cat	&Cat::operator=(const Cat &ref)
{
	std::cout << "Cat Copy Assignment Operator" << std::endl;
	Animal::operator=(ref);
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << this->getType() << ": meows" << std::endl;
}
