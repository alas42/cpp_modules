#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	Bureaucrat bob("bob", 10);
	Form *f[3];

	f[0] = new ShrubberyCreationForm("Bernard");
	f[1] = new RobotomyRequestForm("Paul");
	f[2] = new PresidentialPardonForm("Michael");

	try
	{
		for (int i = 0; i < 3; i++)
			bob.executeForm(*f[i]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		for (int i = 0; i < 3; i++)
			f[i]->beSigned(bob);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		for (int i = 0; i < 3; i++)
			bob.executeForm(*f[i]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < 3; i++)
		delete f[i];
	return 0;
}