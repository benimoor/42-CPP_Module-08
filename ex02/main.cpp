#include "MoutantStack.hpp"

int main()
{
	MutantStack<int> stk;
	
	stk.push(5);
	stk.push(17);
	
	std::cout << stk.top() << std::endl;
	
	stk.pop();
	
	std::cout << stk.size() << std::endl;
	
	stk.push(3);
	stk.push(5);
	stk.push(737);
	stk.push(0);
	
	MutantStack<int>::iterator it = stk.begin();
	MutantStack<int>::iterator ite = stk.end();
	
	++it;
	--it;
	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::stack<int> s(stk);
	
	return 0;
}