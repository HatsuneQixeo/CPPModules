#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*brain;

	public:
		Cat(void);
		Cat(const Cat &ref);
		~Cat(void);
		Cat	&operator=(const Cat &ref);

		Brain	*getBrain(void) const;

		void	makeSound(void) const;
};

#endif
