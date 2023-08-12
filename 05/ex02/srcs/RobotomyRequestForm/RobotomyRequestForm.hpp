#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string	target;

		void	action(void) const;

	public:
		/* Constructor && Destructor */
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &ref);
		~RobotomyRequestForm(void);

		/* OperatorOverload */
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &ref);
};

#endif
