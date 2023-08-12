#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog Default Constructor" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &ref)
{
	std::cout << "Dog Copy Constructor" << std::endl;
	*this = ref;
}

Dog	&Dog::operator=(const Dog &ref)
{
	std::cout << "Dog Copy Assignment Operator" << std::endl;
	Animal::operator=(ref);
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << this->getType() << ": barks" << std::endl;
}
