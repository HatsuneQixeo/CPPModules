#include "Bureaucrat.hpp"

/* Constructor && Destructor */
Bureaucrat::Bureaucrat(const std::string &name, const int grade):
	name(name),
	grade(grade)
{}

Bureaucrat::Bureaucrat(const Bureaucrat &ref):
	name(ref.name),
	grade(ref.grade)
{
	*this = ref;
}


/* OperatorOverload */
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &ref)
{
	this->grade = ref.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{}


/* Getters */
const std::string	&Bureaucrat::getName(void) const
{
	return (this->name);
}

const Grade	&Bureaucrat::getGrade(void) const
{
	return (this->grade);
}


/* MemberFunctions: Grade */
void	Bureaucrat::promote(const unsigned int grade)
{
	std::cout << *this;
	try
	{
		this->grade = this->grade + grade;
		std::cout << " has been promoted into " << this->grade << " grade" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << " couldn't promote [" << grade << "] amount of grade because " << e.what() << std::endl;
	}
}

void	Bureaucrat::demote(const unsigned int grade)
{
	std::cout << *this;
	try
	{
		this->grade = this->grade - grade;
		std::cout << " has been demoted into " << this->grade << " grade" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << " couldn't demote [" << grade << "] amount of grade because " << e.what() << std::endl;
	}
}


/* MemberFunctions: Form */
void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << *this << " couldn't sign " << form << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << *this << " has executed " << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << *this << " couldn't execute " << form << " because " << e.what() << std::endl;
	}
}


/* Log */
std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &bureaucrat)
{
	stream << bureaucrat.getName() << ","
		<< " bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (stream);
}
