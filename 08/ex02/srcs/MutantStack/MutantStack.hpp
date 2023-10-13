#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <iterator>
# include <vector>
# include <deque>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type	container_type;
		typedef typename container_type::iterator		iterator;
	private:

	public:
		/* Constructor && Destructor */
		MutantStack(void);
		MutantStack(const MutantStack<T> &ref);
		~MutantStack(void);

		/* OperatorOverload */
		MutantStack<T>	&operator=(const MutantStack<T> &ref);

		/* Getters */
		MutantStack<T>::iterator	begin(void);
		MutantStack<T>::iterator	end(void);


		/* MemberFunctions */

};

# include "MutantStack.tpp"

#endif
