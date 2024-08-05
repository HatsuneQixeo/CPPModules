#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>

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
		MutantStack(const MutantStack &ref);
		~MutantStack(void);

		/* OperatorOverload */
		MutantStack	&operator=(const MutantStack &ref);

		/* Getters */
		MutantStack::iterator	begin(void);
		MutantStack::iterator	end(void);


		/* MemberFunctions */

};

# include "MutantStack.tpp"

#endif
