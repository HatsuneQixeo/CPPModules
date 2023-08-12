#include "ShrubberyCreationForm.hpp"
#include <fstream>

const std::string	ShrubberyCreationForm::FORM_NAME = "ShrubberyCreationForm";

/* Constructor && Destructor */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	AForm(ShrubberyCreationForm::FORM_NAME, 145, 137),
	target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref): AForm(ref)
{
	*this = ref;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}


/* OperatorOverload */
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
	AForm::operator=(ref);
	this->target = ref.target;
	return (*this);
}


/* MemberFunctions */
void	ShrubberyCreationForm::action(void) const
{
	static const std::string	dictionary("/*\\#$@@  ");
	std::ofstream				outfile(this->target + "_shrubbery");

	if (!outfile.is_open())
	{
		perror(this->target.c_str());
		return ;
	}
	std::srand(std::time(nullptr));
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 39; x++)
			outfile << dictionary[(unsigned int)rand() % dictionary.size()];
		outfile << '\n';
	}
}
