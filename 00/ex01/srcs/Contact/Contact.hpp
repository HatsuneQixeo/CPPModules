#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "lib.hpp"

# define FIRST_NAME		"First Name"
# define LAST_NAME		"Last Name"
# define NICKNAME		"Nickname"
# define PHONE_NUMBER	"Phone Number"
# define DARKEST_SECRET	"DARKEST SECRET"

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

	public:
		const std::string	&get_firstname(void) const;
		const std::string	&get_lastname(void) const;
		const std::string	&get_nickname(void) const;

		bool		empty(void) const;
		void		display(void) const;
		void		add(void);
};

#endif
