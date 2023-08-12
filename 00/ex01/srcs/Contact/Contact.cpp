#include "Contact.hpp"

#define COLON	": "

void	Contact::add(void)
{
	this->first_name = prompt(ENTER(FIRST_NAME), stris::notempty);
	this->last_name = prompt(ENTER(LAST_NAME), stris::notempty);
	this->nickname = prompt(ENTER(NICKNAME), stris::notempty);
	this->phone_number = prompt(ENTER(PHONE_NUMBER), stris::phonenumber);
	this->darkest_secret = prompt(ENTER(DARKEST_SECRET), stris::notempty);
}

void	Contact::display(void) const
{
	if (this->empty())
		std::cout << "Empty Contact" << std::endl;
	else
	{
		std::cout << FIRST_NAME << COLON << this->first_name << '\n'
			<< LAST_NAME << COLON << this->last_name << '\n'
			<< NICKNAME << COLON << this->nickname << '\n'
			<< PHONE_NUMBER << COLON << this->phone_number << '\n'
			<< DARKEST_SECRET << COLON << this->darkest_secret << std::endl;
	}
}

const std::string	&Contact::get_firstname(void) const
{
	return (this->first_name);
}

const std::string	&Contact::get_lastname(void) const
{
	return (this->last_name);
}

const std::string	&Contact::get_nickname(void) const
{
	return (this->nickname);
}

bool	Contact::empty(void) const
{
	return (this->first_name.empty());
}
