#include "Dog.hpp"

Dog::Dog(void):
	brain(new Brain())
{
	std::cout << "Dog Default Constructor" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &ref):
	brain(new Brain())
{
	std::cout << "Dog Copy Constructor" << std::endl;
	*this = ref;
}

Dog	&Dog::operator=(const Dog &ref)
{
	std::cout << "Dog Copy Assignment Operator" << std::endl;
	Animal::operator=(ref);
	*this->brain = *ref.brain;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor" << std::endl;
	delete this->brain;
	this->brain = nullptr;
}

Brain	*Dog::getBrain(void) const
{
	return (this->brain);
}

void	Dog::makeSound(void) const
{
	std::cout << this->getType() << ": barks" << std::endl;
}
