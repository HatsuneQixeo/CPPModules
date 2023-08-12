#ifndef WrongCat_HPP
# define WrongCat_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	private:

	public:
		WrongCat(void);
		WrongCat(const WrongCat &ref);
		~WrongCat(void);
		WrongCat	&operator=(const WrongCat &ref);

		void	makeSound(void) const;
};

#endif
