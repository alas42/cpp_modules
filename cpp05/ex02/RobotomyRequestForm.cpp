#include "RobotomyRequestForm.hpp"

/*
** Canonical Form
*/
RobotomyRequestForm::RobotomyRequestForm(void): Form("John Doe", "robotomy request", 45, 72)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & other): Form(other)
{
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{}

RobotomyRequestForm & RobotomyRequestForm::operator = (RobotomyRequestForm const & other)
{
	Form::operator=(other);
	return *this;
}
/*
** End of Canonical Form
*/

/*
** Other Constructors
*/
RobotomyRequestForm::RobotomyRequestForm(std::string const & target): Form(target, "robotomy request", 45, 72)
{}
/*
** End of Other Constructors
*/

/*
** Misc
*/
void	RobotomyRequestForm::perform(Bureaucrat const & executor) const
{
	std::srand(std::time(0));
	int result = 1 + std::rand()%(2 - 1 + 1) + 1;
	std::cout << "RRRRRRIIIIIIIIIIIIIZZZZZZZZZZZZZZZZZ" << std::endl;
	if (result == 2)
	{
		std::cout << this->getTarget() << " has been successfully robotomized by " << executor.getName() << "." << std::endl;
	}
	else
		throw (RobotomyFailedException());
}
/*
** End of Misc
*/

const char * RobotomyRequestForm::RobotomyFailedException::what() const throw()
{
	return ("the robotomy failed.");
}
/*
** Guetters and Setters
*/
/*
** End of Guetters and Setters
*/
