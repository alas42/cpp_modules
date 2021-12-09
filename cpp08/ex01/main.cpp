#include "span.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

int	main( void )
{
	{ // EASY TESTS
		Span sp = Span(5);
		try
		{
			sp.addNumber(-90);
			sp.addNumber(-50);
			sp.addNumber(5);
			sp.addNumber(11);
			sp.addNumber(54);

			std::cout << MAGENTA << "\nThe shortest span is : " << RESET << sp.shortestSpan() << std::endl;
			std::cout << MAGENTA << "The longest span is : " << RESET << sp.longestSpan() << std::endl;
		}
		catch(std::exception & e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}

	std::cout << std::endl;

	{ // BIG TEST
		try
		{
			int len = 1000;
			int array[len];
			Span sp(len);

			for (int i = 0; i < len; i++)
			{
				if (i == 235)
					array[i] = 18666; // to test if longest span is working
				else
					array[i] = i + (80000 % (i + 5555));
			}

			std::cout << MAGENTA << "size of sp._list: " << RESET << sp.getVector().size() << std::endl;

			int * it = array + 0;
			int * ite = array + len;
			sp.addNumberRange(it, ite);

			std::cout << MAGENTA << "size of sp._list: " << RESET << sp.getVector().size() << "\n" << std::endl;

			for (int i = 0; i < len; i ++)
			{
				std::cout << MAGENTA << "["<< i << "] = " << RESET << sp.getVector().at(i);
				if (!(i % 10 == 9))
					std::cout << " || ";
				else
					std::cout << std::endl;
			}
			std::cout << MAGENTA << "\nThe shortest span is : " << RESET << sp.shortestSpan() << std::endl; //2217 appears twice, maybe others too
			std::cout << MAGENTA << "The longest span is : "  << RESET<< sp.longestSpan() << std::endl;
		}
		catch(std::exception & e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}

	std::cout << std::endl;

	{ // THROWING AN EXCEPTION #1
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

	{ // THROWING AN EXCEPTION #2
		try
		{
			Span sp(1);
			std::cout << MAGENTA << "The shortest span is : " << RESET << sp.shortestSpan() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;	
		}
	}
	return 0;
}