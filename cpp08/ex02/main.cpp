#include "mutantstack.hpp"
#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <algorithm>

int main(void)
{
	MutantStack<int>	empty;
	MutantStack<int>	mstack;
	std::list<int>		mlist;

	mlist.push_back(5);
	mlist.push_back(17);
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "At the back of the list: " << mlist.back() << std::endl;
	std::cout << "At the top of the mutantstack: " << mstack.top() << std::endl;
	mlist.pop_back();
	mstack.pop();

	std::cout << "size of list: " << mlist.size() << std::endl;
	std::cout << "size of mutantstack: " << mstack.size() << std::endl;
	
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	/*
	** ADD HERE
	*/
	mlist.push_back(0);
	mstack.push(0);

	std::list<int>::iterator	itl = mlist.begin();
	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
	++itl;
	--itl;
	++it;
	--it;
	while (it != ite)
	{
		std::cout << "Value in mutantstack: " << *it
			<< " :?: " << *itl << " :Value in list" << std::endl;
		++it;
		++itl;
	}
	empty = mstack;
	MutantStack<int>::iterator	it1 = empty.begin();
	MutantStack<int>::iterator	ite1 = empty.end();
	while (it1 != ite1)
	{
		std::cout << "Value in mutantstack after assignation: " << *it1 << std::endl;
		++it1;
	}
	std::stack<int> s(mstack);
	
	return 0;
}