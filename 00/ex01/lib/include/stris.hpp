#ifndef STRIS_HPP
# define STRIS_HPP

# include <string>
# include <iostream>

typedef bool	(*ft_stris)(const std::string &str);

namespace stris
{
	bool	numeric(const std::string &str);
	bool	validage(const std::string &str);
	bool	validmonth(const std::string &str);
	bool	notempty(const std::string &str);
	bool	whatever(const std::string &str);
	bool	phonenumber(const std::string &str);
	bool	onlymiku(const std::string &str);
}

bool	stris_numberrange(const std::string &type, const std::string &str, int min, int max);

#endif
