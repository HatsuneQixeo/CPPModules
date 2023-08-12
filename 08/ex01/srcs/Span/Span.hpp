#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <numeric>
class Span
{
	public:
		typedef std::vector<int>	Storage;

	private:
		Storage				storage;
		Storage::iterator	view_begin;
		Storage::iterator	view_end;
		bool				sorted;

	public:
		/* Constructor && Destructor */
		Span(const unsigned int N = 0);
		Span(const Span &ref);
		~Span(void);

		/* OperatorOverload */
		Span	&operator=(const Span &ref);

		/* Getters */
		unsigned int	capacity(void) const;
		unsigned int	size(void) const;

		/* MemberFunctions */
		void			sort(void);
		void			addNumber(const int add);
		template <typename It>
		void			addNumber(const It begin, const It end);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);

};

/* Storage Utils */
void			storage_shuffle(Span::Storage &storage);
Span::Storage	storage_createRand(const unsigned int size, const unsigned int randMax = RAND_MAX);
Span::Storage	storage_createAscend(const unsigned int size, const unsigned int multiply = 1);
void			storage_ShortestAndLongest(Span::Storage storage, int &shortest, int &longest);
std::ostream	&operator<<(std::ostream &stream, const Span::Storage &storage);

#endif
