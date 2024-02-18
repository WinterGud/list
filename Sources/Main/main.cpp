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

	sort(l1.begin(), l1.end());
	
	
	return 0;
}
