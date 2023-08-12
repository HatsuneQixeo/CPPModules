#include "Grade.hpp"

/* Constructor and Destructor */
Grade::Grade(const int grade):
	grade(grade)
{
	if (grade < Grade::HIGHEST)
		throw Grade::TooHighException();
	else if (grade > Grade::LOWEST)
		throw Grade::TooLowException();
}

Grade::Grade(const Grade &ref)
{
	*this = ref;
}

Grade::~Grade(void)
{}


/* Operator Overload */
Grade	&Grade::operator=(const Grade &ref)
{
	this->grade = ref.grade;
	return (*this);
}

Grade	Grade::operator+(unsigned int amount) const
{
	/* Throwing exception in the constructor */
	if (amount > Grade::LOWEST - Grade::HIGHEST)
		Grade(Grade::HIGHEST - 1);
	return (Grade(this->grade - amount));
}

Grade	Grade::operator-(unsigned int amount) const
{
	/* Throwing exception in the constructor */
	if (amount > Grade::LOWEST - Grade::HIGHEST)
		Grade(Grade::LOWEST + 1);
	return (Grade(this->grade + amount));
}

bool	Grade::operator>(const Grade &ref) const
{
	return (this->grade < ref.grade);
}

bool	Grade::operator<(const Grade &ref) const
{
	return (this->grade > ref.grade);
}


/* Getters */
int	Grade::getValue(void) const
{
	return (this->grade);
}


/* Exception */
const char	*Grade::TooLowException::what(void) const _NOEXCEPT
{
	return ("Grade: TooLow");
}

const char	*Grade::TooHighException::what(void) const _NOEXCEPT
{
	return ("Grade: TooHigh");
}


/* Log */
std::ostream	&operator<<(std::ostream &stream, const Grade &grade)
{
	stream << grade.getValue();
	return (stream);
}
