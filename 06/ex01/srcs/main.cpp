#include "Serializer.hpp"

int	main(void)
{
	Data	data(1, 2);

	std::cout << std::boolalpha;
	std::cout << (Serializer::deserialize(Serializer::serialize(&data)) == &data) << std::endl;
}
