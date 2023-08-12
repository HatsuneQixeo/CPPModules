#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "Grade.hpp"
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		Grade				grade;

	public:
		/* Constructor && Destructor */
		Bureaucrat(const std::string &name, const int grade);
		Bureaucrat(const Bureaucrat &ref);
		~Bureaucrat(void);

		/* OperatorOverload */
		Bureaucrat	&operator=(const Bureaucrat &ref);

		/* Getters */
		const std::string	&getName(void) const;
		const Grade			&getGrade(void) const;

		/* MemberFunctions: Grade */
		void	promote(const unsigned int grade);
		void	demote(const unsigned int grade);

		/* MemberFunctions: Form */
		void	signForm(Form &form);

};

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);

#endif
