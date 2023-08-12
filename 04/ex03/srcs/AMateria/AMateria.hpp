#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		const std::string	type;

	public:
		AMateria(const std::string &type);
		AMateria(const AMateria &ref);
		virtual ~AMateria(void);
		AMateria	&operator=(const AMateria &ref);

		const std::string	&getType(void) const;

		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
};

#endif
