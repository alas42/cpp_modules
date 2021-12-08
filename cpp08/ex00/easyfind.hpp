#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept>
# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

template < typename C >
void	easyfind(C const & container, int const & to_find)
{
	try
	{
		typename C::const_iterator it = container.begin();
		typename C::const_iterator ite = container.end();
		typename C::const_iterator found = std::find(it, ite, to_find);
		if (found != ite)
		{
			std::cout << "The container contains " << to_find << " at the index " 
				<< std::distance(it, found) << std::endl;
		}
		else
			std::cerr << "The container does not contain " << to_find << std::endl;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

#endif