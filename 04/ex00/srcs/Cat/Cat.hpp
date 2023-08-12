#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
	private:

	public:
		Cat(void);
		Cat(const Cat &ref);
		~Cat(void);
		Cat	&operator=(const Cat &ref);

		void	makeSound(void) const;
};

#endif
