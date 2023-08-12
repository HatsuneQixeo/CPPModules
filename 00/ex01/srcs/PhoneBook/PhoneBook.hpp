#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		static const unsigned int	SIZE = 8;

	private:
		Contact	contacts[SIZE];

		void	new_contact(void);
		void	showbook(void) const;
		void	search(void) const;

		static bool	stris_bookpage(const std::string &str);
	public:
		void	open(void);
};

#endif
