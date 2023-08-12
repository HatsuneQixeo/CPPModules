#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
	private:

	public:
		Ice(void);
		Ice(const Ice &ref);
		~Ice(void);
		Ice	&operator=(const Ice &ref);

		AMateria	*clone(void) const;
		void		use(ICharacter &target);

		static const std::string	TYPE_NAME;
};

#endif
