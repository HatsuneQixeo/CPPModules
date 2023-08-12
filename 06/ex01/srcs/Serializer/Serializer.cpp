#include "Serializer.hpp"

/* Constructor && Destructor */
Serializer::Serializer(void)
{}

Serializer::Serializer(const Serializer &ref)
{
	*this = ref;
}

Serializer::~Serializer(void)
{}


/* Operator Overload */
Serializer	&Serializer::operator=(const Serializer &ref)
{
	return (*this);
	(void)ref;
}


/* MemberFunctions */
uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

