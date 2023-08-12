#include "PhoneBook.hpp"

#define INDEX	"Index"

void	PhoneBook::open(void)
{
	std::string	input;

	std::cout << "ADD:	Add a new contact!" << '\n'
		<< "SEARCH:	Search for existing contacts!" << '\n'
		<< "EXIT:	Quit and forget all added contacts..."  << std::endl;
	while (std::cin.eof() == false)
	{
		input = prompt("Goldfish_Phonebook> ");
		if (input == "ADD")
			this->new_contact();
		else if (input == "SEARCH")
			this->search();
		else if (input == "EXIT")
			return ;
	}
}

void	PhoneBook::new_contact(void)
{
	static int	i = -1;

	this->contacts[++i %= PhoneBook::SIZE].add();
}

void	PhoneBook::search(void) const
{
	this->showbook();
	this->contacts[std::stoi(prompt(ENTER(INDEX), PhoneBook::stris_bookpage))].display();
}

static std::string	rightalign(const std::string &str, unsigned long width = 10, char pad = ' ')
{
	const size_t	size = str.size();

	if (size == width)
		return (str);
	else if (size > width)
		return (std::string(str.substr(0, width - 1)) + '.');
	else
		return (std::string(width - size, pad) + str.data());
}

void	PhoneBook::showbook(void) const
{
	std::cout << rightalign(INDEX) << '|'
		<< rightalign(FIRST_NAME) << '|'
		<< rightalign(LAST_NAME) << '|'
		<< rightalign(NICKNAME) << std::endl;
	for (unsigned int i = 0; i < PhoneBook::SIZE; i++)
	{
		const Contact	&current = this->contacts[i];

		std::cout << rightalign(std::to_string(i)) << '|'
			<< rightalign(current.get_firstname()) << '|'
			<< rightalign(current.get_lastname()) << '|'
			<< rightalign(current.get_nickname()) << std::endl;
	}
}

bool	PhoneBook::stris_bookpage(const std::string &str)
{
	return (stris_numberrange(INDEX, str, 0, PhoneBook::SIZE - 1));
}
