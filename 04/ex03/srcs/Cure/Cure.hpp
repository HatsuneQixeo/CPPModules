#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{
	private:

	public:
		Cure(void);
		Cure(const Cure &ref);
		~Cure(void);
		Cure	&operator=(const Cure &ref);

		AMateria	*clone(void) const;
		void		use(ICharacter &target);

		static const std::string	TYPE_NAME;
};

#endif
