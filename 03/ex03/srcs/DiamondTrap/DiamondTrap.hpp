#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string		name;

	public:
		DiamondTrap(const std::string &name = "D14M0ND-TP");
		DiamondTrap(const DiamondTrap &ref);
		~DiamondTrap(void);
		DiamondTrap	&operator=(const DiamondTrap &ref);
		
		using ScavTrap::attack;
		void	whoAmI(void) const;
};

#endif
