#include "Bureaucrat.hpp"
#include "Form.hpp"

void	tryMake_Form(const std::string &name, const int minGradeSign, const int minGradeExecute)
{
	std::cout << "Constructing: " << name
		<< ", with minGradeSign: " << minGradeSign
		<< ", with minGradeExecute: " << minGradeExecute << '\n';

	try
	{
		const Form	form(name, minGradeSign, minGradeExecute);

		std::cout << "Constructed: " << form << '\n';
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
}

void	testSignForm(void)
{
	Form		miku("Miku Worship Club", 39, 39);
	Bureaucrat	maggot("Maggot1", 139);
	Bureaucrat	me("Miku simp", 39);

	maggot.signForm(miku);
	me.signForm(miku);
	maggot.signForm(miku);
	me.signForm(miku);
}

struct MakeForm
{
	const std::string	name;
	const int			minGradeSign;
	const int			minGradeExecute;
};

int	main(void)
{
	const MakeForm	forms[] = {
		{
			.name = "Highest Execute",
			.minGradeSign = 39,
			.minGradeExecute = Grade::HIGHEST
		},
		{
			.name = "Lowest Execute",
			.minGradeSign = 39,
			.minGradeExecute = Grade::LOWEST
		},
		{
			.name = "Highest Sign",
			.minGradeSign = Grade::HIGHEST,
			.minGradeExecute = 39
		},
		{
			.name = "Lowest Sign",
			.minGradeSign = Grade::LOWEST,
			.minGradeExecute = 39
		},
		{
			.name = "Too High Execute",
			.minGradeSign = 39,
			.minGradeExecute = Grade::HIGHEST - 1
		},
		{
			.name = "Too Low Execute",
			.minGradeSign = 39,
			.minGradeExecute = Grade::LOWEST + 1
		},
		{
			.name = "Too High Sign",
			.minGradeSign = Grade::HIGHEST - 1,
			.minGradeExecute = 39
		},
		{
			.name = "Too Low Sign",
			.minGradeSign = Grade::LOWEST + 1,
			.minGradeExecute = 39
		},
	};
	const size_t	size = (sizeof(forms) / sizeof(forms[0]));

	testSignForm();
	for (unsigned int i = 0; i < size; ++i)
	{
		std::cout << "\033[2J";
		tryMake_Form(forms[i].name, forms[i].minGradeSign, forms[i].minGradeExecute);
		std::cin.get();
	}
}
