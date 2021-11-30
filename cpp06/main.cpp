#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat b0;

	try
	{
		std::cout << b0.getName() << std::endl;
		std::cout << b0.getGrade() << std::endl;
		std::cout << b0 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat b1("Patrick", 151);
		Bureaucrat b2("Pascale", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b3("Patrick-v2", 150);
		std::cout << b3 << std::endl;
		b3.incrementGrade(2);
		std::cout << b3 << std::endl;
		b3.decrementGrade(4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b3("Pascale-v2", 5);
		std::cout << b3 << std::endl;
		b3.incrementGrade(4);
		std::cout << b3 << std::endl;
		b3.decrementGrade(40);
		std::cout << b3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}