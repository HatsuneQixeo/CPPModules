#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const Grade			minGradeSign;
		const Grade			minGradeExecute;

		/* Exception */
		class AlreadySignedException: public std::exception
		{
			public:	const char	*what(void) const _NOEXCEPT;
		};
		class NotSignedException: public std::exception
		{
			public:	const char	*what(void) const _NOEXCEPT;
		};
		virtual void	action(void) const = 0;

	public:
		/* Constructor && Destructor */
		AForm(const std::string &name, int minGradeSign, int minGradeExecute);
		AForm(const AForm &ref);
		virtual ~AForm(void);

		/* OperatorOverload */
		AForm	&operator=(const AForm &ref);

		/* Getters */
		const std::string	&getName(void) const;
		bool				hasBeenSigned(void) const;
		const Grade			&getMinGradeSign(void) const;
		const Grade			&getMinGradeExecute(void) const;

		/* MemberFunctions */
		void	beSigned(const Bureaucrat &bureaucrat);
		void	execute(const Bureaucrat &executor) const;
};

std::ostream	&operator<<(std::ostream &stream, const AForm &form);

#endif
