#include "Bureaucrat.hpp"
#include "Intern.hpp"

void	test(AForm &form)
{
	std::cout << "Test: " << form << '\n' << std::endl;
	Bureaucrat		characters[] = {
		Bureaucrat("Maggot", 139),
		Bureaucrat("Miku simp", 39),
		Bureaucrat("Miku", 01),
	};
	const size_t	size = (sizeof(characters) / sizeof(characters[0]));

	std::cout << "Execute before sign" << std::endl;
	for (unsigned int i = 0; i < size; i++)
		characters[i].executeForm(form);
	std::cout << '\n';

	std::cout << "Signing" << std::endl;
	for (unsigned int i = 0; i < size; i++)
		characters[i].signForm(form);
	std::cout << '\n';

	std::cout << "Repeat Signing" << std::endl;
	for (unsigned int i = 0; i < size; i++)
		characters[i].signForm(form);
	std::cout << '\n';

	std::cout << "Execute" << std::endl;
	for (unsigned int i = 0; i < size; i++)
		characters[i].executeForm(form);
	std::cout << '\n' << std::endl;
}

void	internTest(const std::string &name, const std::string &target)
{
	AForm	*ptr = Intern().makeForm(name, target);

	if (ptr == nullptr)
		return ;
	test(*ptr);
	delete ptr;
}

struct FormName
{
	std::string	name;
	std::string	target;
};

int	main(void)
{
	const FormName	formNames[] = {
		{.name = ShrubberyCreationForm::FORM_NAME, .target = "Home"},
		{.name = RobotomyRequestForm::FORM_NAME, .target = "NotMiku"},
		{.name = PresidentialPardonForm::FORM_NAME, .target = "Who?"},
		{.name = "Try to find this", .target = "Who?"},
	};
	const size_t	size = (sizeof(formNames) / sizeof(formNames[0]));

	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << "\033[2J";
		internTest(formNames[i].name, formNames[i].target);
		std::cin.get();
	}
	system("leaks -q intern");
}
