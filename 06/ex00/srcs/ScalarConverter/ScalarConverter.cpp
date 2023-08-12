#include "ScalarConverter.hpp"
#include <iomanip>

/* Constructor && Destructor */
ScalarConverter::ScalarConverter(void)
{}

ScalarConverter::ScalarConverter(const ScalarConverter &ref)
{
	*this = ref;
}

ScalarConverter::~ScalarConverter(void)
{}


/* Operator Overload */
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &ref)
{
	return (*this);
	(void)ref;
}

/* Utilities */
void	strToLower(std::string &str)
{
	for (size_t i = 0; str[i] != '\0'; i++)
		str[i] = tolower(str[i]);
}

bool	strisNumeric(const std::string &str)
{
	if (str.empty())
		return (false);
	for (size_t i = 0; str[i] != '\0'; i++)
		if (!isdigit(str[i]))
			return (false);
	return (true);
}

/* MemberFunctions: Private */
bool	ScalarConverter::isNumeric(std::string str)
{
	/* std::string::find_first_not_of is gonna return std::string::npos if the string is empty */
	if (str.empty())
		return (false);
	/* Exclude the whitespace prefix */
	str.erase(0, str.find_first_not_of(" \t"));
	/* Exclude the whitespace suffix */
	str.erase(str.find_last_not_of(" \t") + 1);
	/* Case Insensitive */
	strToLower(str);
	/* Exception */
	if (str == "nan" || str == "nanf")
		throw NaNException();
	else if (str == "+inf" || str == "+inff")
		throw PositiveInfinityException();
	else if (str == "-inf" || str == "-inff")
		throw NegativeInfinityException();
	/* Terminate the float suffix */
	if (str.back() == 'f')
		str.pop_back();
	/* Exclude the sign prefix */
	if (str.front() == '+' || str.front() == '-')
		str.erase(0, 1);

	const size_t	decimal_point = str.find('.');

	if (decimal_point == std::string::npos)
		return (strisNumeric(str));
	return (strisNumeric(str.substr(0, decimal_point))
		&& strisNumeric(str.substr(decimal_point + 1)));
}

void	ScalarConverter::logAll(const double value)
{
	if (isprint(value))
		std::cout << "char: " << '\'' << static_cast<char>(value) << '\'' << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	if (ScalarConverter::inRange<int>(value))
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: " << "Overflow" << std::endl;
	std::cout << std::setprecision(1) << std::fixed;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << value << std::endl;
}


/* MemberFunctions: Public */
void	ScalarConverter::convert(const std::string &str)
{
	try
	{
		if (str.empty())
			std::cout << "IsEmpty" << std::endl;
		else if (!isdigit(str.front()) && str[1] == '\0')
			logAll(str.front());
		else if (isNumeric(str))
			logAll(std::stod(str));
		else
			std::cout << "Not an integer: " << str << std::endl;
	}
	catch (const PositiveInfinityException &e)
	{
		std::cout
			<< "char: impossible" << '\n'
			<< "int: impossible" << '\n'
			<< "float: +inff" << '\n'
			<< "double: +inf" << std::endl;
	}
	catch (const NegativeInfinityException &e)
	{
		std::cout
			<< "char: impossible" << '\n'
			<< "int: impossible" << '\n'
			<< "float: -inff" << '\n'
			<< "double: -inf" << std::endl;
	}
	catch (const NaNException &e)
	{
		std::cout
			<< "char: impossible" << '\n'
			<< "int: impossible" << '\n'
			<< "float: nanf" << '\n'
			<< "double: nan" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << ": " << str << std::endl;
	}
}


/* Exception */
const char	*ScalarConverter::NaNException::what(void) const _NOEXCEPT
{
	return ("ScalarConverter: NaN");
}

const char	*ScalarConverter::PositiveInfinityException::what(void) const _NOEXCEPT
{
	return ("ScalarConverter: PositiveInfinity");
}

const char	*ScalarConverter::NegativeInfinityException::what(void) const _NOEXCEPT
{
	return ("ScalarConverter: NegativeInfinity");
}
