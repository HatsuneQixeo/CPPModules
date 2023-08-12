#include "Animal.hpp"

Animal::Animal(void):
	type("Unknown")
{
	std::cout << "Animal Default Constructor" << std::endl;
}

Animal::Animal(const Animal &ref)
{
	std::cout << "Animal Copy Constructor" << std::endl;
	*this = ref;
}

Animal	&Animal::operator=(const Animal &ref)
{
	std::cout << "Animal Copy Assignment Operator" << std::endl;
	this->type = ref.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << this->getType() << ": Unknown sound" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}
