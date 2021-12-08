#include "easyfind.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

int	main( void )
{
	{
		std::vector<int> myvector;
		for (int i = 0; i < 20; i++)
		{
			myvector.push_back((i - 8) % 3);
			std::cout << "i = " << i << " - value " << ((i - 8) % 3) << std::endl;
		}
		::easyfind(myvector, 4);
	}
	{
		std::list<int> mylist;
		for (int i = 0; i < 20; i++)
		{
			mylist.push_back(((i + 41) % 12));
			std::cout << "index = " << i << " - value " << ((i + 41) % 12) << std::endl;
		}
		::easyfind(mylist, 11);
	}
	return 0;
}
