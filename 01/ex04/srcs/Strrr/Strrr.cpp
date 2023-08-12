#include "Strrr.hpp"

# define ANSI_GREY		"\033[0;30m"
# define ANSI_RED		"\033[0;31m"
# define ANSI_GREEN		"\033[0;32m"
# define ANSI_YELLOW	"\033[0;33m"
# define ANSI_BLUE		"\033[0;34m"
# define ANSI_MAGENTA	"\033[0;35m"
# define ANSI_CYAN		"\033[0;36m"

# define ANSI_B_GREY	"\033[0;90m"
# define ANSI_B_RED		"\033[0;91m"
# define ANSI_B_GREEN	"\033[0;92m"
# define ANSI_B_YELLOW	"\033[0;93m"
# define ANSI_B_BLUE	"\033[0;94m"
# define ANSI_B_MAGENTA	"\033[0;95m"
# define ANSI_B_CYAN	"\033[0;96m"

# define ANSI_RESET		"\033[0m"

# define CLASSNAME		"Strrr"
# define CONSTRUCTOR	"Constructor"
# define ASSIGNMENT		"Assignment"
# define ADDITION		"Addition"
# define OPERATOR		"Operator"
# define BASECLASS		"std::string"
# define RAWPOINTER		"Raw Pointer"

/* Constructors && Destructor */
Strrr::Strrr(void)
{
	std::cout << CLASSNAME" Default "CONSTRUCTOR << '\n';
}

Strrr::Strrr(const Strrr &ref):
	std::string(ref)
{
	std::cout << CLASSNAME" Copy "CONSTRUCTOR": ";
	std::cout << ANSI_B_GREY << ref << ANSI_RESET << '\n';
}

Strrr::Strrr(const std::string &ref):
	std::string(ref)
{
	std::cout << CLASSNAME" "BASECLASS" "CONSTRUCTOR": ";
	std::cout << ANSI_B_GREY << ref << ANSI_RESET << '\n';
}

Strrr::Strrr(const char *const str):
	std::string(str)
{
	std::cout << CLASSNAME" "RAWPOINTER" "CONSTRUCTOR": ";
	std::cout << ANSI_B_GREY << str << ANSI_RESET << '\n';
}

Strrr::~Strrr(void)
{
	// std::cout << CLASSNAME" Destructor" << '\n';
}


/* Assignment Operator */
Strrr	&Strrr::operator=(const Strrr &ref)
{
	std::cout << CLASSNAME" "ASSIGNMENT" "OPERATOR": "
		<< ANSI_YELLOW << *this << "] becomes [" << ref
		<< ANSI_RESET << '\n';
	std::string::operator=(ref);
	return (*this);
}

// Strrr	&Strrr::operator=(const std::string &ref)
// {
// 	std::cout << CLASSNAME" "BASECLASS" "ASSIGNMENT" "OPERATOR": "
// 		<< ANSI_YELLOW << *this << "] becomes [" << ref
// 		<< ANSI_RESET << '\n';
// 	std::string::operator=(ref);
// 	return (*this);
// }

Strrr	&Strrr::operator=(const char *ref)
{
	std::cout << CLASSNAME" "RAWPOINTER" "ASSIGNMENT" "OPERATOR": "
		<< ANSI_YELLOW << *this << "] becomes [" << ref
		<< ANSI_RESET << '\n';
	std::string::operator=(ref);
	return (*this);
}


/* Addition Operator */
Strrr	Strrr::operator+(const Strrr &ref) const
{
	std::cout << CLASSNAME" "ADDITION" "OPERATOR": "
		<< ANSI_GREEN << '[' << *this << "] and [" << ref << ']'
		<< ANSI_RESET << '\n';
	return ((std::string&)(*this) + ref);
}

// Strrr	Strrr::operator+(const std::string &ref) const
// {
// 	std::cout << CLASSNAME" "BASECLASS" "ADDITION" "OPERATOR": "
// 		<< ANSI_GREEN << '[' << *this << "] and [" << ref << ']'
// 		<< ANSI_RESET << '\n';
// 	return ((std::string&)(*this) + ref);
// }

Strrr	Strrr::operator+(const char *ref) const
{
	std::cout << CLASSNAME" "RAWPOINTER" "ADDITION" "OPERATOR": "
		<< ANSI_GREEN << '[' << *this << "] and [" << ref << ']'
		<< ANSI_RESET << '\n';
	return ((std::string&)(*this) + ref);
}


/* Compound Addition */
Strrr	&Strrr::operator+=(const Strrr &ref)
{
	std::cout << ANSI_RED << CLASSNAME" Compound Add "OPERATOR": " << ANSI_RESET;
	*this = *this + ref;
	return (*this);
}

// Strrr	&Strrr::operator+=(const std::string &ref)
// {
// 	std::cout << ANSI_RED << CLASSNAME" "" Compound Add "OPERATOR": " << ANSI_RESET;
// 	*this = *this + ref;
// 	return (*this);
// }

Strrr	&Strrr::operator+=(const char *ref)
{
	std::cout << ANSI_RED << CLASSNAME" "RAWPOINTER" Compound Add "OPERATOR": " << ANSI_RESET;
	*this = *this + ref;
	return (*this);
}
