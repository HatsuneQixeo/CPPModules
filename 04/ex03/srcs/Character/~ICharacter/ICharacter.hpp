#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"

class AMateria;

class ICharacter
{
	private:
		ICharacter(const ICharacter &ref);
		ICharacter	&operator=(const ICharacter &ref);

	public:
		ICharacter(void);
		virtual ~ICharacter(void);
		virtual const std::string	&getName(void) const = 0;
		virtual void				equip(AMateria *materia) = 0;
		virtual AMateria			*unequip(unsigned int idx) = 0;
		virtual void				use(unsigned int idx, ICharacter &target) = 0;
};

#endif
