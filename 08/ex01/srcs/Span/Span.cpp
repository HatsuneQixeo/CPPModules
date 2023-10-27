#include "Span.hpp"

/* Constructor && Destructor */
Span::Span(const unsigned int N)
{
	this->reserve(N);
}

Span::Span(const Span &ref)
{
	*this = ref;
}

Span::~Span(void)
{}


/* Operator Overload */
Span	&Span::operator=(const Span &ref)
{
	this->container_type::operator=(ref);
	return (*this);
}


/* Getters */


/* MemberFunctions */
void	Span::addNumber(const value_type add)
{
	if (this->capacity() - this->size() == 0)
		throw std::length_error("Exceed the Maximum Capacity");
	this->push_back(add);
}

unsigned int	Span::shortestSpan(void) const
{
	if (this->size() < 2)
		throw std::length_error("Not Enough Elements");
	std::vector<value_type>	sorted(this->begin(), this->end());
	std::sort(sorted.begin(), sorted.end());

	unsigned int	min_diff = sorted.back() - sorted.front();

	for (std::vector<value_type>::iterator it = sorted.begin() + 1, end = sorted.end();
		it != end;
		++it)
		min_diff = std::min<unsigned int>(*it - *(it - 1), min_diff);
	return (min_diff);
}

unsigned int	Span::longestSpan(void) const
{
	if (this->size() < 2)
		throw std::length_error("Not Enough Elements");
	const value_type	min = *std::min_element(this->begin(), this->end());
	const value_type	max = *std::max_element(this->begin(), this->end());

	return (max - min);
}
