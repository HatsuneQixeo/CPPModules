#include "ScalarConverter.hpp"

// template <typename T>
// void	convertMinMax(void)
// {
// 	std::numeric_limits<T>	limit;

// 	std::cout << "format: " << typeid(T).name() << ": min" << std::endl;
// 	ScalarConverter::convert(std::to_string(limit.lowest()));

// 	std::cout << "format: " << typeid(T).name() << ": max" << std::endl;
// 	ScalarConverter::convert(std::to_string(limit.max()));

// 	std::cout << '\n';
// }

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "usage: ./convert <value>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	// convertMinMax<char>();
	// convertMinMax<int>();
	// convertMinMax<long>();
	// convertMinMax<float>();
	// convertMinMax<double>();
	// (void)argc;
	// (void)argv;
}
