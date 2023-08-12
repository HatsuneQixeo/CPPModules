#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

template <typename T>
void	test(const std::string &name)
{
	T				form(name);
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

struct TestFunc
{
	const std::string	name;
	void				(*func)(const std::string &name);
};

int	main(void)
{
	const TestFunc	tests[] = {
		{.name = "Home", .func = test<ShrubberyCreationForm>},
		{.name = "NotMiku", .func = test<RobotomyRequestForm>},
		{.name = "Who?", .func = test<PresidentialPardonForm>},
	};
	const size_t	size = (sizeof(tests) / sizeof(tests[0]));

	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << "\033[2J";
		tests[i].func(tests[i].name);
		std::cin.get();
	}
}
