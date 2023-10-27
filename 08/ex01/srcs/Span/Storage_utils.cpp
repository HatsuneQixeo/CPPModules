#include "Span.hpp"

Span::container_type	storage_createRand(const unsigned int size, const unsigned int randMax)
{
	Span::container_type	storage(size);

	for (unsigned int i = 0; i < size; i++)
		storage[i] = rand() % (randMax + 1);
	return (storage);
}

std::ostream	&operator<<(std::ostream &stream, const Span::container_type &storage)
{
	for (Span::container_type::const_iterator it = storage.begin(); it != storage.end(); it++)
	{
		if (it != storage.begin())
			stream << ", ";
		stream << *it;
	}
	return (stream);
}
