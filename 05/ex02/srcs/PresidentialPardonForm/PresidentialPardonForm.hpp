#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string	target;

		void	action(void) const;

	public:
		/* Constructor && Destructor */
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &ref);
		~PresidentialPardonForm(void);

		/* OperatorOverload */
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &ref);
};

#endif
