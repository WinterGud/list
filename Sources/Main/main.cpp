#include "list.hpp"
#include <list>
#include <iostream>


int main()
{

	list<int> l1;
	l1.push_back(4);
	std::cout << l1.last();
	

	return 0;
}