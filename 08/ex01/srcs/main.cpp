#include "Span.hpp"

void	showSpan(Span &span)
{
	std::cout << "Shortest: " << span.shortestSpan() << std::endl;
	std::cout << "Longest : " << span.longestSpan() << std::endl;
}

void	subjectTest(void)
{
	std::cout << "Test given by subject" << std::endl;
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	showSpan(sp);
	std::cout << std::endl;
}

void	testNegative(void)
{
	Span	span(4);

	std::cout << "Test Negative" << std::endl;
	span.addNumber(-1);
	span.addNumber(2);
	span.addNumber(-3);
	span.addNumber(4);
	showSpan(span);
	std::cout << std::endl;
}

void	testMinMax(void)
{
	Span	span(3);

	std::cout << "Test Overflow" << std::endl;
	span.addNumber(INT_MIN);
	span.addNumber(INT_MAX - 1);
	span.addNumber(INT_MAX);
	showSpan(span); /* shortest should be 1 */
	std::cout << std::endl;
}

#define TRY(code, shouldThrow) \
{\
	try {\
		code;\
		if ((shouldThrow))\
			std::cout << "Missing exception for "#code"\n";\
	}\
	catch (const std::exception &e) {\
		if (!(shouldThrow))\
			std::cout << "Unexpected exception for "#code"\n";\
	}\
}

void	testException(const unsigned int size)
{
	std::vector<int>	vec(size);
	Span				span(size);

	std::cout << "Exception Testing size: " << size << std::endl;
	TRY(span.shortestSpan(), true);
	TRY(span.longestSpan(), true);
	TRY(span.addNumber(1), size == 0);
	TRY(span.shortestSpan(), true);
	TRY(span.longestSpan(), true);
	TRY(span.addNumber(vec.begin(), vec.end()), size != 0);
	TRY(span.addNumber(1), size <= 1);
	TRY(span.shortestSpan(), size <= 1);
	TRY(span.longestSpan(), size <= 1);
	if (size > 1)
		TRY(span.addNumber(vec.begin(), vec.end() - 2), false);
	TRY(span.addNumber(39), true);
	TRY(span.addNumber(vec.begin(), vec.end()), size != 0);
	TRY(span.shortestSpan(), size <= 1);
	TRY(span.longestSpan(), size <= 1);
	std::cout << std::endl;
}

void	testNormal(Span::Storage storage)
{
	if (storage.size() < 2)
		throw std::runtime_error("TestNormal is not meant to handle any exception");
	Span	span(storage.size());

	std::cout << "Test Normal" << '\n';
	std::cout << "Adding this into span: " << storage << '\n';
	span.addNumber(storage.begin(), storage.end());
	std::cout << "Added into Span" << '\n';
	showSpan(span);
	std::sort(storage.begin(), storage.end());
	std::cout << "Sorted Storage: " << storage << '\n';
	std::cout << std::endl;
}

int	main(void)
{
	srand(time(nullptr));
	try
	{
#if 1
		subjectTest();
#endif
#if 0 /* Normal Test */
		testNormal(storage_createRand(10, 831));
		testNegative();
		testMinMax();
#endif
#if 0/* Exception test */
		testException(0);
		testException(1);
		testException(2);
		testException(3);
		testException(39);
		testException(831);
#endif
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: Unexpected exception: " << e.what() << std::endl;
	}
}
