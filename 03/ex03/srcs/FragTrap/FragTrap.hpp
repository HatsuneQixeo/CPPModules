#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	protected:
		static const unsigned int	HEALTH = 100;
		static const unsigned int	ENERGY = 100;
		static const unsigned int	ATTACK = 30;
	public:
		FragTrap(const std::string &name = "FR4G-TP");
		FragTrap(const FragTrap &ref);
		~FragTrap(void);
		FragTrap	&operator=(const FragTrap &ref);

		void	highFivesGuys(void);
};

#endif
