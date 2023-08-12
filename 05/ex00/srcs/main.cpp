#include "Bureaucrat.hpp"

void	gradeOverflow(void)
{
	std::cout << "testOverflow" << std::endl;

	std::cout << "Promote overflow" << std::endl;
	Bureaucrat("Unknown", Grade::HIGHEST).promote(1);
	Bureaucrat("Unknown", Grade::LOWEST).promote(INT32_MAX);
	Bureaucrat("Unknown", Grade::LOWEST).promote(INT32_MIN);
	Bureaucrat("Unknown", Grade::LOWEST).promote(UINT32_MAX);

	std::cout << "Demote overflow" << std::endl;
	Bureaucrat("Unknown", Grade::LOWEST).demote(1);
	Bureaucrat("Unknown", Grade::HIGHEST).demote(INT32_MAX);
	Bureaucrat("Unknown", Grade::HIGHEST).demote(INT32_MIN);
	Bureaucrat("Unknown", Grade::HIGHEST).demote(UINT32_MAX);
}

void	constructTry(const std::string &name, const int grade)
{
	try
	{
		std::cout << "Constructing " << name << " of grade: " << grade << '\n';
		std::cout << Bureaucrat(name, grade) << '\n'
			<< "Construction Suceed" << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception Thrown: " << e.what() << '\n';
	}
	std::cout << std::endl;
}

void	testConstruct(void)
{
	std::cout << "testConstruct" << std::endl;

	/* Too high */
	constructTry("YEEHAW", Grade::HIGHEST - 1);
	/* Too low*/
	constructTry("yeehaw", Grade::LOWEST + 1);
	/* Highest */
	constructTry("YEEHAW", Grade::HIGHEST);
	/* Lowest */
	constructTry("yeehaw...", Grade::LOWEST);
}

void	testUnary(void)
{
	std::cout << "testUnary" << std::endl;
	Bureaucrat	test("MikuSimp", 39);

	std::cout << test << std::endl;
	test.promote(1);
	std::cout << "After Promotion: " << test << std::endl;
	test.demote(1);
	std::cout << "After Demotion : " << test << std::endl;
	std::cout << '\n';

	/* Too High */
	std::cout << "Promote too much: " << std::endl;
	test.promote(831);
	/* Too Low */
	std::cout << "Demote too much: " << std::endl;
	test.demote(831);

	std::cout << test << std::endl;
	std::cout << '\n';
}

int	main(void)
{
	typedef void	(*const ft_test)(void);
	const ft_test	arr[] = {
		testUnary,
		testConstruct,
		gradeOverflow,
	};
	const size_t	size = (sizeof(arr) / sizeof(arr[0]));

	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << "\033[2J";
		arr[i]();
		std::cin.get();
	}
}
