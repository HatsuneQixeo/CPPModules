#include "Span.hpp"

/* Constructor && Destructor */
Span::Span(const unsigned int N):
	storage(N),
	view_begin(this->storage.begin()),
	view_end(this->view_begin),
	sorted(false)
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
	this->sorted = ref.sorted;
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
void	Span::sort(void)
{
	if (this->sorted == true)
		return ;
	std::sort(this->view_begin, this->view_end);
	this->sorted = true;
}

void	Span::addNumber(const int add)
{
	if (this->view_end == this->storage.end())
		throw std::length_error("Exceed the Maximum Capacity");
	*this->view_end++ = add;
	this->sorted = false;
}

unsigned int	Span::shortestSpan(void)
{
	unsigned int	diffMin = this->longestSpan();

	for (Storage::iterator it = this->view_begin + 1; it != this->view_end; it++)
		diffMin = std::min<unsigned int>(*it - *(it - 1), diffMin);
	return (diffMin);
}

unsigned int	Span::longestSpan(void)
{
	if ((this->view_end - this->view_begin) <= 1)
		throw std::runtime_error("Not Enough Elements");
	this->sort();
	return (*(view_end - 1) - *view_begin);
}
