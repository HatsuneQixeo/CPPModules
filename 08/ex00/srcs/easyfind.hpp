#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <class T>
typename T::iterator	easyfind(T &container, const int ref)
{
	return (std::find(container.begin(), container.end(), ref));
}

#endif
