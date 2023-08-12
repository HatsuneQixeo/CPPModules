#ifndef STRRR_HPP
# define STRRR_HPP

# include <iostream>

struct Strrr: public std::string
{
	/* Constructors */
	Strrr(void);
	Strrr(const Strrr &ref);
	Strrr(const std::string &ref);
	Strrr(const char *const str);
	~Strrr(void);

	/* Assignment Operator */
	Strrr	&operator=(const Strrr &ref);
	// Strrr	&operator=(const std::string &ref);
	Strrr	&operator=(const char *ref);

	/* Addition Operator */
	Strrr	operator+(const Strrr &ref) const;
	// Strrr	operator+(const std::string &ref) const;
	Strrr	operator+(const char *ref) const;

	/* Compound Addition */
	Strrr	&operator+=(const Strrr &ref);
	// Strrr	&operator+=(const std::string &ref);
	Strrr	&operator+=(const char *ref);
};

#endif
