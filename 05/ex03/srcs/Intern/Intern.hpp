#ifndef INTERN_HPP
# define INTERN_HPP

# include <array>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:

	public:
		/* Constructor && Destructor */
		Intern(void);
		Intern(const Intern &ref);
		~Intern(void);

		/* OperatorOverload */
		Intern	&operator=(const Intern &ref);

		/* Getters */


		/* MemberFunctions */
		AForm	*makeForm(const std::string &name, const std::string &target);

};

#endif
