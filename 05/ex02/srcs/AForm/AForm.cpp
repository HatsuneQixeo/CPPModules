#include "AForm.hpp"

/* Constructor && Destructor */
AForm::AForm(const std::string &name, const int minGradeSign, const int minGradeExecute):
	name(name),
	isSigned(false),
	minGradeSign(minGradeSign),
	minGradeExecute(minGradeExecute)
{}

AForm::AForm(const AForm &ref):
	name(ref.name),
	isSigned(false),
	minGradeSign(ref.minGradeSign),
	minGradeExecute(ref.minGradeExecute)
{}

AForm::~AForm(void)
{}


/* OperatorOverload */
AForm	&AForm::operator=(const AForm &ref)
{
	return (*this);
	(void)ref;
}


/* Getters */
const std::string	&AForm::getName(void) const
{
	return (this->name);
}

bool	AForm::hasBeenSigned(void) const
{
	return (this->isSigned);
}

const Grade	&AForm::getMinGradeSign(void) const
{
	return (this->minGradeSign);
}

const Grade	&AForm::getMinGradeExecute(void) const
{
	return (this->minGradeExecute);
}


/* MemberFunctions */
void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->isSigned == true)
		throw AForm::AlreadySignedException();
	else if (bureaucrat.getGrade() < this->minGradeSign)
		throw Grade::TooLowException();
	else
		this->isSigned = true;
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (this->isSigned == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() < this->minGradeExecute)
		throw Grade::TooLowException();
	else
		this->action();
}


/* Exception */
const char	*AForm::AlreadySignedException::what(void) const _NOEXCEPT
{
	return ("AForm::HasBeenSigned");
}

const char	*AForm::NotSignedException::what(void) const _NOEXCEPT
{
	return ("AForm::NoSignature");
}


/* Log */
std::ostream	&operator<<(std::ostream &stream, const AForm &form)
{
	stream << "[" << form.getName() << "]"
		<< ", gradeSign: " << form.getMinGradeSign()
		<< ", gradeExecute: " << form.getMinGradeExecute()
		<< ", (" << (form.hasBeenSigned() ? "Signed" : "Not Signed") << ")";
	return (stream);
}
