#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	type;

	public:
		Animal(void);
		Animal(const Animal &ref);
		virtual ~Animal(void);
		Animal	&operator=(const Animal &ref);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
