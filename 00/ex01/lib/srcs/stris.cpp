#include "stris.hpp"

bool	stris::whatever(const std::string &str)
{
	return (true);
	(void)str;
}

bool	stris::notempty(const std::string &str)
{
	if (str.empty())
		std::cout << "This field could not be left empty" << std::endl;
	return (str.empty() == false);
}

bool	stris::numeric(const std::string &str)
{
	int	i;

	i = 0;
	if (!stris::notempty(str))
		return (false);
	while (isspace(str[i]))
		i++;
	if (strchr("+-", str[i]))
		i++;
	if (str[i] == '\0')
		std::cout << "Missing digit" << std::endl;
	while (isdigit(str[i]))
		i++;
	if (str[i])
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
	int	i;

	if (str.empty())
		return (false);
	i = 0;
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
		if (nbr >= min && nbr <= max)
			return (true);
		std::cout << nbr << " is not a valid " << type << std::endl;
		std::cout << "Please enter a value within " << min << " - " << max << ')' << std::endl;
	}
	return (false);
}

bool	stris::onlymiku(const std::string &str)
{
	std::string	lower(str);
	const bool	isMiku = (lower == "hatsune miku");

	std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
	if (str == "HATSUNE MIKU")
		std::cout << "ソフトウェアを怖がらせるしないでください!" << std::endl;
	if (isMiku)
		std::cout << "こんにちはマスター、私はあなたに憧れていました!" << std::endl;
	else
		std::cout << "Hatsune Miku is waiting for your call..." << std::endl;
	return (isMiku);
}
