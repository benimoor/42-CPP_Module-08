#include "Span.hpp"

int main()
{
	Span spanir = Span(5);
	
	std::vector<int> MyBigVector;

	spanir.addNumber(6);
	spanir.addNumber(3);
	spanir.addNumber(17);
	spanir.addNumber(9);
	spanir.addNumber(11);
	
	std::cout << spanir.shortestSpan() << std::endl;
	std::cout << spanir.longestSpan() << std::endl;
	
	spanir.addRandomNums(MyBigVector, 10000);	

	try
	{
		spanir.addRange(MyBigVector.begin(), MyBigVector.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Span sp_1(20000);
	try
	{
		sp_1.addRandomNums(MyBigVector, 10000);
		sp_1.addRange(MyBigVector.begin(), MyBigVector.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}