#ifndef MUTANTSTAK_HPP
#define MUTANTSTAK_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

template <typename T>

class MutantStack : public std::stack<T>
{
public:
	MutantStack() { };
	MutantStack(const MutantStack& other) { *this = other; };
	MutantStack& operator = (const MutantStack& other)
	{
		if (this != &other)
			this->c = other.c;
		return *this;
	};
	~MutantStack() { };

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator	begin()	{ return this->c.begin(); };
	iterator	end()	{ return this->c.end(); };
};


#endif