#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:

	public:
		ScavTrap(const std::string &name = "SC4V-TP");
		ScavTrap(const ScavTrap &ref);
		~ScavTrap(void);
		ScavTrap	&operator=(const ScavTrap &ref);

		void	attack(const std::string &target);
		void	guardGate(void);
};

#endif
