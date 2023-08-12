#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	protected:
		static const unsigned int	HEALTH = 100;
		static const unsigned int	ENERGY = 50;
		static const unsigned int	ATTACK = 20;
	public:
		ScavTrap(const std::string &name = "SC4V-TP");
		ScavTrap(const ScavTrap &ref);
		~ScavTrap(void);
		ScavTrap	&operator=(const ScavTrap &ref);

		void	attack(const std::string &target);
		void	guardGate(void);
};

#endif
