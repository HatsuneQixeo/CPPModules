#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define ANSI_RESET		"\x1b[0m"
# define ANSI_BLACK		"\x1b[30m"
# define ANSI_RED		"\x1b[31m"
# define ANSI_GREEN		"\x1b[32m"
# define ANSI_YELLOW	"\x1b[33m"
# define ANSI_BLUE		"\x1b[34m"
# define ANSI_MAGENTA	"\x1b[35m"
# define ANSI_CYAN		"\x1b[36m"
# define ANSI_WHITE		"\x1b[37m"

// Background color
# define ANSI_BG_BLACK		"\x1b[40m"
# define ANSI_BG_RED		"\x1b[41m"
# define ANSI_BG_GREEN		"\x1b[42m"
# define ANSI_BG_YELLOW		"\x1b[43m"
# define ANSI_BG_BLUE		"\x1b[44m"
# define ANSI_BG_MAGENTA	"\x1b[45m"
# define ANSI_BG_CYAN		"\x1b[46m"
# define ANSI_BG_WHITE		"\x1b[47m"

class ClapTrap
{
	private:
		std::string		type;
		unsigned int	maxHP;
		std::string		name;
		unsigned int	hp;
		unsigned int	ep;
		int				atk;

	public:
		ClapTrap(const std::string &name = "CL4P-TP");
		ClapTrap(const ClapTrap &ref);
		~ClapTrap(void);
		ClapTrap	&operator=(const ClapTrap &ref);

		void			attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		bool			isalive(void) const;
		void			showStatus(void) const;

		std::string		getType(void) const;
		std::string		getName(void) const;
		unsigned int	getHP(void) const;
		unsigned int	getEP(void) const;
		int				getAtk(void) const;
};

std::ostream	&operator<<(std::ostream &stream, const ClapTrap &ref);

#endif
