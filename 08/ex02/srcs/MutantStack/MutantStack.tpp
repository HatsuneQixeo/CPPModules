#ifndef MUTANT_STACK_TPP
# define MUTANT_STACK_TPP

# include "MutantStack.hpp"

/* Constructor && Destructor */
template <typename T>
MutantStack<T>::MutantStack(void)
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &ref)
{
	*this = ref;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{}


/* Operator Overload */
template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &ref)
{
	std::stack<T>::operator=(ref);
	return (*this);
}


/* Getters */
template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (this->c.end());
}


/* MemberFunctions */


#endif
