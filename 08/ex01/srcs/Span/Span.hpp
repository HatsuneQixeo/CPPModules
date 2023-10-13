#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span
{
	public:
		typedef std::vector<int>	Storage;
		typedef Storage::value_type	value_type;

	private:
		Storage				storage;
		Storage::iterator	view_begin;
		Storage::iterator	view_end;

	public:
		/* Constructor && Destructor */
		explicit Span(const unsigned int N = 0);
		Span(const Span &ref);
		~Span(void);

		/* OperatorOverload */
		Span	&operator=(const Span &ref);

		/* Getters */
		unsigned int	capacity(void) const;
		unsigned int	size(void) const;

		/* MemberFunctions */
		void			addNumber(const value_type add);
		template <typename Iterator>
		void			addNumber(const Iterator begin, const Iterator end);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

};

template <typename Iterator>
void	Span::addNumber(const Iterator begin, const Iterator end)
{
	const size_t	insert_size = std::distance(begin, end);

	if (insert_size == 0)
		return ;
	if (this->capacity() - this->size() < insert_size)
		throw std::length_error("Exceed the Maximum Capacity");
	std::copy(begin, end, this->view_end);
	this->view_end += insert_size;
}

/* Storage Utils */
Span::Storage	storage_createRand(const unsigned int size, const unsigned int randMax = RAND_MAX);
std::ostream	&operator<<(std::ostream &stream, const Span::Storage &storage);

#endif
