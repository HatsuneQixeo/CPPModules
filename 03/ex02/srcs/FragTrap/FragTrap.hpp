#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	private:

	public:
		FragTrap(const std::string &name = "FR4G-TP");
		FragTrap(const FragTrap &ref);
		~FragTrap(void);
		FragTrap	&operator=(const FragTrap &ref);

		void	highFivesGuys(void);
};

#endif
