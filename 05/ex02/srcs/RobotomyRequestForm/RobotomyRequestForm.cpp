#include "RobotomyRequestForm.hpp"

/* Constructor && Destructor */
RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	AForm("RobotomyRequestForm", 72, 45),
	target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref): AForm(ref)
{
	*this = ref;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{}


/* OperatorOverload */
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
	AForm::operator=(ref);
	this->target = ref.target;
	return (*this);
}


/* MemberFunctions */
void	RobotomyRequestForm::action(void) const
{
	std::cout << "* Loud and aggressive drilling noise at some kind of metal *" << std::endl;
	if (rand() & 1)
		std::cout << this->target << " has successfully been robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}
