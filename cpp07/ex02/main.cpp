#include "Array.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

#define MAX_VAL 20

int main(int, char**)
{
	{
		std::cout << GREEN << "Creation of Array<int> numbers and int * mirror" << RESET << std::endl;

		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];

		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
			std::cout << "numbers[" << i << "] : " << numbers[i] << "|| mirror[" << i << "] : " << mirror[i] << std::endl;
		}

		{
			std::cout << GREEN<< "Test: assignation (tmp) and copy construcor (test)" << RESET << std::endl;
			Array<int> tmp = numbers;
			Array<int> test(tmp);
			unsigned int test_size = test.size();
			for (unsigned int i = 0; i < test_size; i++)
				std::cout << "tmp[" << i << "] : " << tmp[i] << "|| test[" << i << "] : " << test[i] << std::endl;
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << RED << "didn't save the same value!!" << RESET << std::endl;
				return 1;
			}
		}


		std::cout << std::endl;


		try
		{
			std::cout << MAGENTA << "Test: numbers[-2] = 0" << RESET << std::endl;
			numbers[-2] = 0;
			std::cout << GREEN << "It works!" << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << '\n';
		}

		try
		{
			std::cout << MAGENTA << "Test: numbers[MAX_VAL] = 0" << RESET << std::endl;
			numbers[MAX_VAL] = 0;
			std::cout << GREEN << "It works!" << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << '\n';
		}

		try
		{
			std::cout << MAGENTA << "Test: numbers[5] = 3" << RESET << std::endl;
			numbers[5] = 3;
			std::cout << GREEN << "It works!" << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << '\n';
		}

		delete [] mirror;
	}


	std::cout << std::endl;
	
	
	{
		std::string tab_string[10] = {"Art", "Baston", "Carton", "Dino", "Erst", "Franche", "Guirlande", "Helico", "Icare", "Juin"}; 
		Array<std::string> strings(10);
		
		srand(time(NULL));
		for (int i = 0; i < 10; i++)
		{
			const int value = rand() % 10;
			strings[i] = tab_string[value];
			std::cout << "strings[" << i << "] : " << strings[i] << std::endl;
		}

		std::cout << "Array<std::string> strings has a size of " << strings.size() << std::endl;
	}
	
	return 0;
}

