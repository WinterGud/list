#include "list.hpp"
#include <list>
#include <iostream>


int main()
{

	list<int> l1(6);
	for(int i = 0; i < l1.size(); i++)
	std::cout << l1.last() << '\t';
	

	return 0;
}