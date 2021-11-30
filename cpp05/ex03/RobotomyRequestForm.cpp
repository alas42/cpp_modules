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
	int result = 1 + std::rand()/((RAND_MAX + 1u)/2);
	if (result == 1)
		std::cout << "RRRRRRIIIIIIIIIIIIIZZZZZZZZZZZZZZZZZ  " << this->getTarget() << " has been successfully robotomized by " << executor.getName() << "." << std::endl;
	else
		std::cout << "RRRRRRIIIIIIIIIIIIIZZZZZZZZZZZZZZZZZ  " << this->getTarget() << " wasn't robotomized, " << executor.getName() << " failed." << std::endl;
}

Form	* RobotomyRequestForm::printingForm(std::string const & target)
{
	return new RobotomyRequestForm(target);
}
/*
** End of Misc
*/

/*
** Guetters and Setters
*/
/*
** End of Guetters and Setters
*/
