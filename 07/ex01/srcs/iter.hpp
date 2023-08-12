#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename Func>
void	iter(T *arr, const size_t length, Func func)
{
	for (size_t i = 0; i < length; i++)
		func(arr[i]);
}

template <typename T>
void	showEndl(T &ele)
{
	std::cout << ele << '\n';
}

template <typename T>
void	showBrace(T &ele)
{
	std::cout << " [" << ele << "] ";
}

template <typename T>
void	showComma(T &ele)
{
	std::cout << ele << ", ";
}

template <typename T>
void	showSpace(T &ele)
{
	std::cout << ele << ' ';
}

template <typename T>
void	show(T &ele)
{
	std::cout << ele;
}

void	increment(int &ele);
void	decrement(int &ele);
void	testInt(void);

void	ft_toupper(char &c);
void	ft_tolower(char &c);
void	ft_capitalize(char &c);
void	testString(void);

void	strToUpper(std::string &ele);
void	strToLower(std::string &ele);
void	strCapitalize(std::string &ele);
void	testStrlist(void);

#endif
