#include "PresidentialPardonForm.hpp"

/*
** Canonical Form
*/
PresidentialPardonForm::PresidentialPardonForm(void): Form("John Doe", "presidential pardon form", 5, 25)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & other): Form(other)
{
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{}

PresidentialPardonForm & PresidentialPardonForm::operator = (PresidentialPardonForm const & other)
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
PresidentialPardonForm::PresidentialPardonForm(std::string const & target): Form(target, "presidential pardon form", 5, 25)
{}
/*
** End of Other Constructors
*/

/*
** Misc
*/
void	PresidentialPardonForm::perform(Bureaucrat const & executor) const
{
	std::cout << this->getTarget() << " has been pardoned by " << executor.getName() << "." << std::endl;
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
