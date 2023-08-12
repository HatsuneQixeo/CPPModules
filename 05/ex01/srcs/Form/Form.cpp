#include "Form.hpp"

/* Constructor && Destructor */
Form::Form(const std::string &name, const int minGradeSign, const int minGradeExecute):
	name(name),
	isSigned(false),
	minGradeSign(minGradeSign),
	minGradeExecute(minGradeExecute)
{}

Form::Form(const Form &ref):
	name(ref.name),
	isSigned(false),
	minGradeSign(ref.minGradeSign),
	minGradeExecute(ref.minGradeExecute)
{}

Form::~Form(void)
{}


/* OperatorOverload */
Form	&Form::operator=(const Form &ref)
{
	return (*this);
	(void)ref;
}


/* Getters */
const std::string	&Form::getName(void) const
{
	return (this->name);
}

bool	Form::hasBeenSigned(void) const
{
	return (this->isSigned);
}

const Grade	&Form::getMinGradeSign(void) const
{
	return (this->minGradeSign);
}

const Grade	&Form::getMinGradeExecute(void) const
{
	return (this->minGradeExecute);
}


/* MemberFunctions */
void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->isSigned == true)
		throw Form::AlreadySignedException();
	else if (bureaucrat.getGrade() < this->minGradeSign)
		throw Grade::TooLowException();
	else
		this->isSigned = true;
}


/* Exception */
const char	*Form::AlreadySignedException::what(void) const _NOEXCEPT
{
	return ("Form: HasBeenSigned");
}


/* Log */
std::ostream	&operator<<(std::ostream &stream, const Form &form)
{
	stream << "[" << form.getName() << "]"
		<< ", gradeSign: " << form.getMinGradeSign()
		<< ", gradeExecute: " << form.getMinGradeExecute()
		<< ", (" << (form.hasBeenSigned() ? "Signed" : "Not Signed") << ")";
	return (stream);
}
