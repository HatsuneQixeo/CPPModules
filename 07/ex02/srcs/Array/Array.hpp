#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T				*data;
		unsigned int	length;

	public:
		/* Constructor && Destructor */
		Array(void);
		Array(unsigned int length);
		Array(const Array<T> &ref);
		~Array(void);

		/* OperatorOverload */
		Array<T>	&operator=(const Array<T> &ref);
		bool		operator==(const Array<T> &ref) const;
		const T		&operator[](unsigned int i) const;
		T			&operator[](unsigned int i);

		/* Getters */
		unsigned int	size(void) const;

		/* MemberFunctions */
		void	resize(unsigned int size);
		void	clear(void);


		/* Exception */
};

# include "Array.tpp"

#endif
