#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &ref);
		virtual ~WrongAnimal(void);
		WrongAnimal	&operator=(const WrongAnimal &ref);

		std::string	getType(void) const;
		void		makeSound(void) const;
};

#endif
