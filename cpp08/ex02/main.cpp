#include "mutantstack.hpp"
#include <iostream>
#include <stack>
#include <list>
#include <algorithm>

int main(void)
{
	MutantStack<int>	mstack;
	std::list<int>		mlist;

	mlist.push_back(5);
	mstack.push(5);

	mlist.push_back(17);
	mstack.push(17);

	std::cout << MAGENTA << "size of list: " << RESET << mlist.size() << std::endl;
	std::cout << MAGENTA << "size of mutantstack: " << RESET << mstack.size() << std::endl;
	
	mlist.pop_back();
	mstack.pop();

	mlist.push_back(3);
	mstack.push(3);
	
	mlist.push_back(5);
	mstack.push(5);

	mlist.push_back(737);
	mstack.push(737);
	
	std::cout << MAGENTA << "size of list: " << RESET << mlist.size() << std::endl;
	std::cout << MAGENTA << "size of mutantstack: " << RESET << mstack.size() << std::endl;
	
	std::cout << MAGENTA << "At the back of the list: " << RESET << mlist.back() << std::endl;
	std::cout << MAGENTA << "At the top of the mutantstack: " << RESET << mstack.top() << std::endl;

	mlist.push_back(0);
	mstack.push(0);

	std::cout << std::endl;

	{ // LOOPING THROUGH THE LIST AND THE MUTANTSTACK
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
	}

	std::cout << std::endl;

	{ // ASSIGNATION TEST
		MutantStack<int>	empty;
		empty = mstack;
	
		MutantStack<int>::iterator	it1 = empty.begin();
		MutantStack<int>::iterator	ite1 = empty.end();
		while (it1 != ite1)
		{
			std::cout << "Value in mutantstack after assignation: " << *it1 << std::endl;
			++it1;
		}
	}

	std::cout << std::endl;

	{ // CREATION OF A STANDARD STACK BASED ON OUR MUTANTSTACK
		std::stack<int> s(mstack);
	}

	return 0;
}