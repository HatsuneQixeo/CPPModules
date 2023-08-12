#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie(std::string name = "zombie");
		~Zombie(void);
		void	announce(void) const;
};

Zombie	*zombieHorde(int n, std::string name);


#endif
