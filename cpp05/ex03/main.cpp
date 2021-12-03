#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	Intern  someRandomIntern;
	Bureaucrat bob("Bob", 4);
	Form*   rrf[4];

	for (int i = 0; i < 4; i++)
	{
		rrf[i] = 0;
	}
	try
	{
		rrf[0] = someRandomIntern.makeForm("robotomy request", "Bender");
		rrf[1] = someRandomIntern.makeForm("shrubbery creation", "Paul");
		rrf[2] = someRandomIntern.makeForm("presidential pardon", "Theo");
		//rrf[3] = someRandomIntern.makeForm("crash ?", "Hercules");
		for (int i = 0; i < 4; i++)
		{
			if (rrf[i] != 0)
			{
				bob.signForm(*rrf[i]);
				bob.executeForm(*rrf[i]);
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	for (int i = 0; i < 4; i++)
	{
		if (rrf[i] != 0)
			delete rrf[i];
	}
}