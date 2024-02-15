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
	for (auto it = l1.begin(); it != l1.end(); it++)
	{
		std::cout << it << '\t';
	}
	l1.erase(l1.begin());
	std::cout << --l1.end();
	
	return 0;
}