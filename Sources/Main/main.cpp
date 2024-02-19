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
		std::cout << *it << '\n';
	}

	for (auto it : l1)
	{
		std::cout << it << '\n';
	}
	l1.clear();
	
	
	return 0;
}
