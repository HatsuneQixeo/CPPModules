#include "PresidentialPardonForm.hpp"

const std::string	PresidentialPardonForm::FORM_NAME = "PresidentialPardonForm";

/* Constructor && Destructor */
PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	AForm(PresidentialPardonForm::FORM_NAME, 25, 5),
	target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref): AForm(ref)
{
	*this = ref;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{}


/* OperatorOverload */
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
	AForm::operator=(ref);
	this->target = ref.target;
	return (*this);
}


/* MemberFunctions */
void	PresidentialPardonForm::action(void) const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
