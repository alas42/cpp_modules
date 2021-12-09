#include "easyfind.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

int	main( void )
{
	std::cout << GREEN << "Test with container#1 : vector" << RESET << std::endl;
	{

		std::vector<int>	myvector;
		int					len = 20;

		for (int i = 0; i < len; i ++)
		{
			myvector.push_back((i - 8) % 3);
			std::cout << MAGENTA << "["<< i << "] = " << RESET << ((i - 8) % 3);
			if (!(i % 10 == 9))
				std::cout << " || ";
			else
				std::cout << std::endl;
		}

		::easyfind(myvector, 4);
	}

	std::cout << "\n" << GREEN << "Test with container#2 : list" << RESET << std::endl;

	{
		std::list<int>	mylist;
		int				len = 20;

		for (int i = 0; i < len; i++)
		{
			mylist.push_back(((i + 41) % 12));
			std::cout << MAGENTA << "["<< i << "] = " << RESET << ((i + 41) % 12);
			if (!(i % 10 == 9))
				std::cout << " || ";
			else
				std::cout << std::endl;
		}

		::easyfind(mylist, 11);
	}

	std::cout << "\n" << GREEN << "Test with container#3 : deque" << RESET << std::endl;

	{
		std::deque<int>	mydeque;
		int				len = 20;

		for (int i = 0; i < len; i++)
		{
			mydeque.push_back(((i + 41) % 12));
			std::cout << MAGENTA << "["<< i << "] = " << RESET << ((i + 41) % 12);
			if (!(i % 10 == 9))
				std::cout << " || ";
			else
				std::cout << std::endl;
		}

		::easyfind(mydeque, 11);
	}

	return 0;
}
