#include "list.hpp"
#include <list>
#include <iostream>


int main()
{

	list<int> l1(6);
	list<int>::iterator it(l1.begin());
	std::cout << it;
	
	return 0;
}