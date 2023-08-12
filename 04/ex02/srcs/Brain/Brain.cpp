#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain Default Constructor" << std::endl;
}

Brain::Brain(const Brain &ref)
{
	std::cout << "Brain Copy Constructor" << std::endl;
	*this = ref;
}

Brain	&Brain::operator=(const Brain &ref)
{
	std::cout << "Brain Copy Assignment Operator" << std::endl;
	for (unsigned int i = 0; i < Brain::CAPACITY; i++)
		this->ideas[i] = ref.ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor" << std::endl;
	for (unsigned int i = 0; i < Brain::CAPACITY; i++)
		this->ideas[i].clear();
}

void	Brain::addIdea(const std::string &ref, unsigned int i)
{
	if (i >= Brain::CAPACITY)
		return ;
	this->ideas[i] = ref;
}

std::string	Brain::getIdea(unsigned int i) const
{
	if (i >= Brain::CAPACITY)
		return ("");
	return (this->ideas[i]);
}

void	Brain::showIdeas(void) const
{
	for (unsigned int i = 0; i < Brain::CAPACITY; i++)
	{
		if (this->ideas[i].empty())
			continue ;
		std::cout << "ideas[" << i << "]: " << this->ideas[i] << std::endl;
	}
}
