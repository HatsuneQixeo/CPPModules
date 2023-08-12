#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*brain;

	public:
		Dog(void);
		Dog(const Dog &ref);
		~Dog(void);
		Dog	&operator=(const Dog &ref);

		Brain	*getBrain(void) const;

		void	makeSound(void) const;
};

#endif
