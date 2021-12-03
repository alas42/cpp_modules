#include "Bureaucrat.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat b0;
			std::cout << "[Guetters and operators overload <<]" << std::endl;
			std::cout << "getName(): " << b0.getName() << std::endl;
			std::cout << "getGrade(): " << b0.getGrade() << std::endl;
			std::cout << "<<: " << b0 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		std::cout << std::endl;
	}
	{
		try
		{
			Bureaucrat b1("Patrick", 151);
			Bureaucrat b2("Pascale", 50);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		std::cout << std::endl;
	}
	{
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
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}

	return 0;
}