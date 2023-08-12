#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter
{
	public:
		static const unsigned int	INVENTORY_SIZE = 4;

	private:
		std::string	name;
		AMateria	*inventory[INVENTORY_SIZE];

	public:
		Character(const std::string &name);
		Character(const Character &ref);
		~Character(void);

		Character	&operator=(const Character &ref);

		const std::string	&getName(void) const;
		void				equip(AMateria *materia);
		AMateria			*unequip(unsigned int idx);
		void				use(unsigned int idx, ICharacter &target);
};

#endif
