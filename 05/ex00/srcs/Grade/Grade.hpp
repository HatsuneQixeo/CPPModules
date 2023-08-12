#ifndef GRADE_HPP
# define GRADE_HPP

# include <iostream>
# include <exception>

class Grade
{
	public:
		static const int	HIGHEST = 1;
		static const int	LOWEST = 150;

	private:
		int	grade;

	public:
		/* Constructor && Destructor */
		Grade(const int grade);
		Grade(const Grade &ref);
		~Grade(void);

		/* OperatorOverload */
		Grade	&operator=(const Grade &ref);
		Grade	operator+(unsigned int amount) const;
		Grade	operator-(unsigned int amount) const;
		bool	operator>(const Grade &ref) const;
		bool	operator<(const Grade &ref) const;

		/* Getters */
		int	getValue(void) const;

		/* MemberFunctions */

		/* Exception */
		class TooLowException: public std::exception
		{
			public: const char	*what(void) const _NOEXCEPT;
		};
		class TooHighException: public std::exception
		{
			public:	const char	*what(void) const _NOEXCEPT;
		};

};

std::ostream	&operator<<(std::ostream &stream, const Grade &grade);

#endif
