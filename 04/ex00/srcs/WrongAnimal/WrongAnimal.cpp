#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void):
	type("Unknown")
{
	std::cout << "WrongAnimal Default Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
{
	std::cout << "WrongAnimal Copy Constructor" << std::endl;
	*this = ref;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &ref)
{
	std::cout << "WrongAnimal Copy Assignment Operator" << std::endl;
	this->type = ref.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Destructor" << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << this->getType() << ": Wrong unknown sound" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}
