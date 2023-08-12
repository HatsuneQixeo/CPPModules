#include "MutantStack.hpp"
#include <stack>
#include <vector>

/**
 * @brief Should I make a generic test function for it?
 * With container and push function as template
 * 
 * @return int 
 */

int	main(void)
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) 
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}
