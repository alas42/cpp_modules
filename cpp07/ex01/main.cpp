#include <iostream>
#include <string>
#include "iter.hpp"

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

int	main( void )
{
	int		len = 20; 
	int		tab_integer[len];
	std::string tab_string[10] = {"Art", "Baston", "Carton", "Dino", "Erst", "Franche", "Guirlande", "Helico", "Icare", "Juin"}; 

	for (int i = 0; i < len; i++)
	{
		tab_integer[i] = (i * 8) % 6;
	}
	std::cout << GREEN << "iter on an array of int" << RESET << std::endl;
	::iter(tab_integer, len, &::print_elem);
	std::cout << std::endl;
	std::cout << GREEN << "iter on an array of string" << RESET << std::endl;
	::iter(tab_string, 10, &::print_elem);
	return 0;
}
