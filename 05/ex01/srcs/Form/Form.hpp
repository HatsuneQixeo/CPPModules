#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
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

	public:
		/* Constructor && Destructor */
		Form(const std::string &name, const int minGradeSign, const int minGradeExecute);
		Form(const Form &ref);
		~Form(void);

		/* OperatorOverload */
		Form	&operator=(const Form &ref);

		/* Getters */
		const std::string	&getName(void) const;
		bool				hasBeenSigned(void) const;
		const Grade			&getMinGradeSign(void) const;
		const Grade			&getMinGradeExecute(void) const;

		/* MemberFunctions */
		void	beSigned(const Bureaucrat &bureaucrat);
};

std::ostream	&operator<<(std::ostream &stream, const Form &form);

#endif
