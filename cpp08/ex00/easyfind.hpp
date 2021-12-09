#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept>
# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

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
			std::cout
				<< GREEN << "The container contains " << RESET
				<< to_find
				<< GREEN << " at the index " << RESET
				<< std::distance(it, found)
				<< std::endl;
		}
		else
			std::cerr << RED << "The container does not contain " << RESET << to_find << std::endl;

	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

#endif