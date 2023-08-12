#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>

class ScalarConverter
{
	private:
		/* Constructor */
		ScalarConverter(const ScalarConverter &ref);

		/* OperatorOverload */
		ScalarConverter	&operator=(const ScalarConverter &ref);

		/* MemberFunctions */
		static bool	isNumeric(std::string str);
		static void	logAll(const double value);

	public:
		/* Constructor && Destructor */
		ScalarConverter(void);
		~ScalarConverter(void);


		/* MemberFunctions */
		static void	convert(const std::string &str);
		template <typename T, typename V>
		static bool	inRange(const V value)
		{
			std::numeric_limits<T>	limit;

			return (limit.lowest() <= value && value <= limit.max());
		}

		/* Exception */
		class NaNException: public std::exception
		{
			public:	const char	*what(void) const _NOEXCEPT;
		};
		class PositiveInfinityException: public std::exception
		{
			public:	const char	*what(void) const _NOEXCEPT;
		};
		class NegativeInfinityException: public std::exception
		{
			public:	const char	*what(void) const _NOEXCEPT;
		};
};

#endif
