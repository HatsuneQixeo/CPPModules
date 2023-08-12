#include "Character.hpp"

Character::Character(const std::string &name):
	name(name)
{
	bzero(this->inventory, sizeof(this->inventory));
}

Character::Character(const Character &ref):
	name(ref.name)
{
	bzero(this->inventory, sizeof(this->inventory));
	*this = ref;
}

Character	&Character::operator=(const Character &ref)
{
	this->~Character();
	for (unsigned int i = 0; i < Character::INVENTORY_SIZE; i++)
	{
		if (ref.inventory[i] != nullptr)
			this->inventory[i] = ref.inventory[i]->clone();
	}
	return (*this);
}

Character::~Character(void)
{
	for (unsigned int i = 0; i < Character::INVENTORY_SIZE; i++)
		delete this->inventory[i];
	bzero(this->inventory, sizeof(this->inventory));
}

const std::string	&Character::getName(void) const
{
	return (this->name);
}

void	Character::equip(AMateria *materia)
{
	if (materia == nullptr)
		return ;
	for (unsigned int i = 0; i < Character::INVENTORY_SIZE; i++)
	{
		if (this->inventory[i] == nullptr)
		{
			this->inventory[i] = materia;
			return ;
		}
	}
	std::cout << this->name << " could not equip " << materia->getType()
		<< " becuase the inventory is full" << std::endl;
}

AMateria	*Character::unequip(unsigned int idx)
{
	if (idx >= Character::INVENTORY_SIZE)
	{
		std::cout << idx << " is not a valid index within "
			<< this->name << "'s inventory size: " << Character::INVENTORY_SIZE << std::endl;
		return (nullptr);
	}
	AMateria	*materia = this->inventory[idx];

	this->inventory[idx] = nullptr;
	return (materia);
}

/* Returns the integer along with it's ordinal suffix in string */
std::string	ordinalSuffix(const int n)
{
	const std::string	str = std::to_string(n);
	const int			nbr = abs(n);

	if (nbr != 11 && nbr != 12 && nbr != 13)
	{
		switch (n % 10)
		{
			case 1:
				return (str + "st");
			case 2:
				return (str + "nd");
			case 3:
				return (str + "rd");
		}
	}
	return (str + "th");
}

void	Character::use(unsigned int idx, ICharacter &target)
{
	if (idx >= Character::INVENTORY_SIZE)
		std::cout << idx << " is not a valid index within "
			<< this->name << "'s inventory size: " << Character::INVENTORY_SIZE << std::endl;
	else if (this->inventory[idx] == nullptr)
		std::cout << this->name << " does not have anything equipped in the "
			<< ordinalSuffix(idx + 1) << " slot" << std::endl;
	else
	{
		std::cout << "[" << this->getName() << "] ";
		this->inventory[idx]->use(target);
	}
}
