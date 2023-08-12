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
}

void	testNegative(void)
{
	std::cout << "Test Negative" << std::endl;
	Span	span(4);

	span.addNumber(-1);
	span.addNumber(2);
	span.addNumber(-3);
	span.addNumber(4);
	showSpan(span);
}

void	testMinMax(void)
{
	std::cout << "Test INT_MIN INT_MAX" << std::endl;
	Span	span(4);

	span.addNumber(39);
	span.addNumber(INT_MIN);
	span.addNumber(INT_MAX);
	span.addNumber(831);
	showSpan(span);
}

#define TRY(code, shouldThrow) \
{\
	try {\
		code;\
		if ((shouldThrow))\
			std::cout << "Missing throw for " << #code << std::endl;\
	}\
	catch (const std::exception &e) {\
		if (!(shouldThrow))\
			std::cout << "Unexpected throw for " << #code << std::endl;\
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
	TRY(span.addNumber(vec.begin(), vec.end()), vec.size() != 0);
	TRY(span.addNumber(1), size <= 1);
	TRY(span.shortestSpan(), size <= 1);
	TRY(span.longestSpan(), size <= 1);
	if (size > 1)
		TRY(span.addNumber(vec.begin(), vec.end() - 2), false);
	TRY(span.addNumber(39), true);
	TRY(span.addNumber(vec.begin(), vec.end()), vec.size() != 0);
	TRY(span.shortestSpan(), size <= 1);
	TRY(span.longestSpan(), size <= 1);
}

void	testNormal(Span::Storage storage)
{
	if (storage.size() < 2)
	{
		std::cout << "TestNormal is not meant to handle any exception" << std::endl;
		return ;
	}
	Span	span(storage.size());

	std::cout << "Before Shuffle: " << storage << std::endl;

	storage_shuffle(storage);
	std::cout << "After Shuffle: " << storage << std::endl;

	span.addNumber(storage.begin(), storage.end());
	std::cout << "Added into Span" << std::endl;

	showSpan(span);

	std::sort(storage.begin(), storage.end());
	std::cout << "Sorted Storage: " << storage << std::endl;
}

int	main(void)
{  
	srand(time(nullptr));
	/* Normal Test */
#if 1
	testNormal(storage_createRand(10, 831));
	testNormal(storage_createAscend(10, 39));
	subjectTest();
	testNegative();
	testMinMax();
#endif
	/* Exception test */
#if 0
	testException(0);
	testException(1);
	testException(2);
	testException(3);
	testException(39);
	testException(831);
#endif
}

/*
	Some Leftover test that is meant to discover the container feature
*/

// void	insertTest(void)
// {
// 	const size_t		size = 3;
// 	std::vector<int>	vec(size);

// 	for (unsigned int i = 0; i < size; i++)
// 		vec[i] = i;
// 	std::cout << vec << std::endl;
// 	/* Overload: It (pos), value */
// 	vec.insert(vec.begin(), 9);
// 	std::cout << vec << std::endl;

// 	/* Overload: It (pos), amount, value */
// 	vec.insert(vec.begin(), 3, 5);
// 	std::cout << vec << std::endl;

// 	/* Overload: It (pos), begin, end */
// 	vec.insert(vec.begin(), vec.begin(), vec.end());
// 	std::cout << vec << std::endl;
// }
