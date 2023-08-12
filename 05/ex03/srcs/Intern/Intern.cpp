#include "Intern.hpp"

Intern::Intern(void)
{}

Intern::Intern(const Intern &ref)
{
	*this = ref;
}

Intern::~Intern(void)
{}


/* Operator Overload */
Intern	&Intern::operator=(const Intern &ref)
{
	return (*this);
	(void)ref;
}


/* MemberFunctions */
AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	AForm			*arr[] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target),
	};
	const size_t	size = (sizeof(arr) / sizeof(arr[0]));
	AForm			*ret = nullptr;

	for (unsigned int i = 0; i < size; i++)
	{
		if (arr[i]->getName() == name)
			ret = arr[i];
		else
			delete arr[i];
	}
	if (ret == nullptr)
		std::cout << "Intern: No such form: " << name << std::endl;
	else
		std::cout << "Intern creates " << *ret << std::endl;
	return (ret);
}
