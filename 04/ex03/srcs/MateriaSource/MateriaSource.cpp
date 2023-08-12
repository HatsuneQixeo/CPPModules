#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	bzero(this->storage, sizeof(this->storage));
}

MateriaSource::MateriaSource(const MateriaSource &ref)
{
	bzero(this->storage, sizeof(this->storage));
	*this = ref;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &ref)
{
	this->~MateriaSource();
	for (unsigned int i = 0; i < MateriaSource::STORAGE_SIZE; i++)
	{
		if (ref.storage[i] != nullptr)
			this->storage[i] = ref.storage[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (unsigned int i = 0; i < MateriaSource::STORAGE_SIZE; i++)
		delete this->storage[i];
	bzero(this->storage, sizeof(this->storage));
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	if (materia == nullptr)
		return ;
	for (unsigned int i = 0; i < MateriaSource::STORAGE_SIZE; i++)
	{
		if (this->storage[i] == nullptr)
		{
			this->storage[i] = materia;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (unsigned int i = 0; i < MateriaSource::STORAGE_SIZE; i++)
	{
		if (this->storage[i] == nullptr)
			continue ;
		else if (this->storage[i]->getType() == type)
			return (this->storage[i]->clone());
	}
	return (nullptr);
}
