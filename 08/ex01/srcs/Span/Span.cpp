#include "Span.hpp"

/* Constructor && Destructor */
Span::Span(const unsigned int N):
	storage(N),
	view_begin(this->storage.begin()),
	view_end(this->view_begin)
{}

Span::Span(const Span &ref)
{
	*this = ref;
}

Span::~Span(void)
{}


/* Operator Overload */
Span	&Span::operator=(const Span &ref)
{
	this->storage = ref.storage;
	this->view_begin = ref.view_begin;
	this->view_end = ref.view_end;
	return (*this);
}


/* Getters */
unsigned int	Span::capacity(void) const
{
	return (this->storage.size());
}

unsigned int	Span::size(void) const
{
	return (this->view_end - this->view_begin);
}


/* MemberFunctions */
void	Span::addNumber(const value_type add)
{
	if (this->capacity() - this->size() == 0)
		throw std::length_error("Exceed the Maximum Capacity");
	*this->view_end++ = add;
}

unsigned int	Span::shortestSpan(void) const
{
	if (this->size() < 2)
		throw std::length_error("Not Enough Elements");
	Storage	sorted(this->view_begin, this->view_end);
	std::sort(sorted.begin(), sorted.end());

	unsigned int	min_diff = sorted.back() - sorted.front();

	for (Storage::iterator it = sorted.begin() + 1, end = sorted.end();
		it != end;
		++it)
		min_diff = std::min<unsigned int>(*it - *(it - 1), min_diff);
	return (min_diff);
}

unsigned int	Span::longestSpan(void) const
{
	if (this->size() < 2)
		throw std::length_error("Not Enough Elements");
	const value_type	min = *std::min_element(this->view_begin, this->view_end);
	const value_type	max = *std::max_element(this->view_begin, this->view_end);

	return (max - min);
}
