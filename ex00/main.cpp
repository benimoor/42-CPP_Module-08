#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> a(5, 0);
	a.push_back(3);
	std::vector<int>::iterator gago = easyfind(a, 4);
	std::cout << *gago << std::endl;
	return 0;
}