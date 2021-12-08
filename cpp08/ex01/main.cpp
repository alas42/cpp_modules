#include "span.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

int	main( void )
{
	{
		Span sp = Span(5);
		try
		{
			sp.addNumber(-90);
			sp.addNumber(-50);
			sp.addNumber(5);
			sp.addNumber(11);
			sp.addNumber(54);

			std::cout << "The shortest span is : " << sp.shortestSpan() << std::endl;
			std::cout << "The longest span is : " << sp.longestSpan() << std::endl;
		}
		catch(std::exception & e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			int len = 10000;
			int array[len];
			Span sp(len);
			for (int i = 0; i < len; i++)
			{
				if (i == 235)
					array[i] = 18666;
				else
					array[i] = i + (8000000 % 98656);
			}
			int * it = array + 0;
			int * ite = array + len;
			sp.addNumberRange(it, ite);
			std::cout << "size of sp._list: " << sp.getVector().size() << std::endl;

			for (int i = 0; i < len; i ++)
			{
				std::cout << i << ": " << sp.getVector().at(i);
				if (!(i % 10 == 9))
					std::cout << " || ";
				else
					std::cout << std::endl;
			}
			std::cout << "The shortest span is : " << sp.shortestSpan() << std::endl;
			std::cout << "The longest span is : " << sp.longestSpan() << std::endl;
		}
		catch(std::exception & e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Span sp(0);
			sp.addNumber(1);
		}
		catch (std::exception & e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;	
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Span sp(1);
			std::cout << "The shortest span is : " << sp.shortestSpan() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;	
		}
	}
	return 0;
}