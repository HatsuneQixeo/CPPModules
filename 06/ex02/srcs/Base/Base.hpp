#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>

class Base
{
	public:
		virtual ~Base(void) {};
		virtual void	who(void) const = 0;
};

#endif
