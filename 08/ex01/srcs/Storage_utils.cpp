#include "Span.hpp"

void	storage_shuffle(Span::Storage &storage)
{
	const unsigned int	size = storage.size();

	for (unsigned int i = 0; i < size; i++)
		std::swap(storage[i], storage[rand() % size]);
}

Span::Storage	storage_createRand(const unsigned int size, const unsigned int randMax)
{
	Span::Storage	storage(size);

	for (unsigned int i = 0; i < size; i++)
		storage[i] = rand() % (randMax + 1);
	return (storage);
}

Span::Storage	storage_createAscend(const unsigned int size, const unsigned int multiply)
{
	Span::Storage	storage(size);

	for (unsigned int i = 0; i < size; i++)
		storage[i] = i * multiply;
	return (storage);
}

/* Why? */
void	storage_ShortestAndLongest(Span::Storage storage, int &shortest, int &longest)
{
	std::sort(storage.begin(), storage.end());
	longest = storage.back() - storage.front();
	shortest = longest;
	for (Span::Storage::iterator it = storage.begin() + 1; it != storage.end(); it++)
		shortest = std::min(shortest, *it - *(it - 1));
}

/* Am I still using this? */
std::ostream	&operator<<(std::ostream &stream, const Span::Storage &storage)
{
	for (Span::Storage::const_iterator it = storage.begin(); it != storage.end(); it++)
	{
		if (it != storage.begin())
			stream << ", ";
		stream << *it;
	}
	return (stream);
}
