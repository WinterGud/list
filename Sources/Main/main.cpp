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

	partition(l1.begin(), l1.end());
	find(l1.begin(), l1.end(), 2);
	
	return 0;
}
