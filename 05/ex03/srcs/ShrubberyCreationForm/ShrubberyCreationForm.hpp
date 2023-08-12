#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		static const std::string	FORM_NAME;

	private:
		std::string	target;

		void	action(void) const;

	public:
		/* Constructor && Destructor */
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &ref);
		~ShrubberyCreationForm(void);

		/* OperatorOverload */
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &ref);
};

#endif
