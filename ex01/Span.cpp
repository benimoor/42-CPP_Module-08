#include "Span.hpp"

Span::Span() { _SpanirVector.reserve(0); }

Span::Span(unsigned int N) { _SpanirVector.reserve(N); }

Span::Span(const Span& other)
{
	this->_SpanirVector.clear();
	this->_SpanirVector.reserve(other._SpanirVector.capacity());
	this->_SpanirVector = other._SpanirVector;
}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_SpanirVector.clear();
		this->_SpanirVector.reserve(other._SpanirVector.capacity());
		this->_SpanirVector = other._SpanirVector;
	}
	return *this;
}

Span::~Span() { _SpanirVector.clear(); }

const char	*Span::NotEnoughSpaceException::what() const throw()	{ return "Not enough space in span to add new elements!"; }
const char	*Span::SpanIsFullException::what() const throw()		{ return "Can't add new element (span already full)!"; }
const char	*Span::NotEnoughElementsException::what() const throw()	{ return "Not enough elements for a span!"; }


void	Span::addRandomNums(std::vector<int>& vec, int size)
{
	std::srand(time(0));
	for (int i = 0; i < size; i++)
		vec.push_back(std::rand());
}

void	Span::addNumber(int n)
{
	if (_SpanirVector.size() == _SpanirVector.capacity())
	{
		throw	SpanIsFullException();
		return ;
	}
	_SpanirVector.push_back(n);
}

void	Span::addRange(it begin, it end)
{
	if (end < begin)
		return ;
	if (static_cast<unsigned int>(std::distance(begin, end)) > (_SpanirVector.capacity() - _SpanirVector.size()))
		throw NotEnoughSpaceException();
	
	_SpanirVector.insert(_SpanirVector.end(), begin, end);

	std::cout << std::distance(begin, end) << " integers added to span!" << std::endl;

}

unsigned int	Span::shortestSpan()
{
	if (_SpanirVector.size() < 2)
	{
		throw NotEnoughElementsException();
		return -1;
	}
	
	std::vector<int> sortVec(_SpanirVector);
	std::sort(sortVec.begin(), sortVec.end());
	
	unsigned int min = -1;

	for (std::vector<int>::iterator it = sortVec.begin(); it + 1 != sortVec.end(); it++)
	{
		if (static_cast<unsigned int>(*(it + 1) - *it) < min)
			min = static_cast<unsigned int>(*(it + 1) - *it);
	}
	std::cout << "The shortest span is\t";
	return min;
}

unsigned int	Span::longestSpan()
{
	if (_SpanirVector.size() < 2)
	{
		throw NotEnoughElementsException();
		return -1;
	}
	
	std::vector<int> sortVec(_SpanirVector);
	std::sort(sortVec.begin(), sortVec.end());
	
	std::vector<int>::iterator begin = sortVec.begin();
	std::vector<int>::iterator end = sortVec.end();

	unsigned int max = static_cast<unsigned int>(*(end - 1) - *begin);
	std::cout << "The longest span is\t";
	return max;
}