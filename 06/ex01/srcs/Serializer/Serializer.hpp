#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"

class Serializer
{
	private:
		/* Constructor && Destructor */
		Serializer(const Serializer &ref);
		~Serializer(void);

		/* OperatorOverload */
		Serializer	&operator=(const Serializer &ref);
	public:
		/* Constructor && Destructor */
		Serializer(void);


		/* Getters */


		/* MemberFunctions */
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif
