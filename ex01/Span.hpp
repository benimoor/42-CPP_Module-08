#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>


typedef std::vector<int>::iterator it;

class Span
{
	std::vector<int>	_SpanirVector;
public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator = (const Span& other);
	~Span();

	void			addRandomNums(std::vector<int> &vec, int size);
	void			addRange(it begin, it end);
	void			addNumber(int n);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	class	SpanIsFullException : public std::exception
	{
		const char	*what() const throw();
	};
	
	class	NotEnoughElementsException : public std::exception
	{
		const char	*what() const throw();
	};
	
	class	NotEnoughSpaceException : public std::exception
	{
		const char	*what() const throw();
	};	
};

#endif