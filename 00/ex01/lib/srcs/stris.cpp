#include "stris.hpp"

/**
 * Look at all these impure functions man,
 * nobody would ever uses this library if I ended up making it a thing
 */

bool	stris::whatever(const std::string &str)
{
	return (true);
	(void)str;
}

bool	stris::notempty(const std::string &str)
{
	if (str.empty())
		std::cout << "This field could not be left empty" << std::endl;
	else
		return (true);
	return (false);
}

bool	stris::numeric(const std::string &str)
{
	unsigned int	i = 0;

	if (!stris::notempty(str))
		return (false);
	i = str.find_first_not_of(" \t\n\r\v\f");
	i += ((str[i] == '+') || (str[i] == '-'));
	if (str[i] == '\0')
	{
		std::cout << "Missing value" << std::endl;
		return (false);
	}
	i = str.find_first_not_of("0123456789", i);
	if (str[i] != '\0')
		std::cout << "Containing something else other than digit" << std::endl;
	return (str[i] == '\0');
}

bool	stris::validage(const std::string &str)
{
	return (stris_numberrange("Age", str, 0, INT_MAX));
}

bool	stris::validmonth(const std::string &str)
{
	return (stris_numberrange("Month", str, 1, 12));
}

static bool	phonenumber_format(const std::string &str);
bool	stris::phonenumber(const std::string &str)
{
	bool	format;

	format = phonenumber_format(str);
	if (str.empty())
		std::cout << "Please enter a phone number" << std::endl;
	else if (format == false)
		std::cout << "Phone number should not contain character other than integer" << ','
			<< " space or +/- sign" << std::endl;
	return (format);
}

static bool	phonenumber_format(const std::string &str)
{
	unsigned int	i = 0;

	if (str.empty())
		return (false);
	while (str[i] != '\0'
		&& (isspace(str[i]) || isdigit(str[i]) || strchr("+-", str[i])))
		i++;
	return (str[i] == '\0');
}

bool	stris_numberrange(const std::string &type, const std::string &str, int min, int max)
{
	int	nbr;

	if (str.empty())
		std::cout << "Please enter a number" << std::endl;
	else if (stris::numeric(str))
	{
		nbr = atoi(str.data());
		if (min <= nbr && nbr <= max)
			return (true);
		std::cout << nbr << " is not a valid " << type << std::endl;
		std::cout << "Please enter a value within " << min << " - " << max << ')' << std::endl;
	}
	return (false);
}

std::string	miniphone(std::string str)
{
	for (unsigned int i = 0; i < str.size(); i++)
		str[i] = tolower(str[i]);
	return (str);
}

bool	stris::onlymiku(const std::string &str)
{
	const std::string	lower = miniphone(str);
	const bool			isMiku = (lower == "hatsune miku");

	if (str == "HATSUNE MIKU")
		std::cout << "ソフトウェアを怖がらせるしないでください!" << std::endl;
	if (isMiku)
		std::cout << "こんにちはマスター、私はあなたに憧れていました!" << std::endl;
	else
		std::cout << "Hatsune Miku is waiting for your call..." << std::endl;
	return (isMiku);
}
