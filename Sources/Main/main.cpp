#include "list.hpp"
#include <list>
#include <iostream>


int main()
{

	list<int> l1;
	for (int i = 0; i < 4; i++)
	{
		l1.push_back(i);
	}
	std::cout << l1.size() << '\n';
	std::cout << *l1.begin() << '\n';
	
	l1.insert(l1.begin(), 6);
	std::cout << l1.size() << '\n';
	std::cout << l1.front() << '\n';
	std::cout << *find(l1.begin(), l1.end(), 10) << '\n';
	
	return 0;
}