#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

# define DEBUG		"DEBUG"
# define INFO		"INFO"
# define WARNING	"WARNING"
# define ERROR		"ERROR"

class Harl
{
	private:
		typedef void	(Harl::*ft_action)(void) const;
		struct ActionPair
		{
			std::string	name;
			ft_action	func;
		};
		static const size_t		ACTION_COUNT = 4;
		static const ActionPair	actions[ACTION_COUNT];

		void	debug(void) const;
		void	info(void) const;
		void	warning(void) const;
		void	error(void) const;

		static int	filter_level(std::string level);

	public:
		Harl(void);
		~Harl(void);

		void	complain(std::string level) const;
		void	filter(std::string level);
};

#endif
