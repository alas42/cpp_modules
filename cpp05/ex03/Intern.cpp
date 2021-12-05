#include "Intern.hpp"

/*
** Canonical Form
*/
Intern::Intern(void)
{}

Intern::Intern(Intern const & other)
{
	*this = other;
}

Intern::~Intern(void)
{}

Intern & Intern::operator = (Intern const & other)
{
	if (this == &other)
		return *this;
	return *this;
}
/*
** End of Canonical Form
*/

/*
** Other Constructors
*/
/*
** End of Other Constructors
*/

/*
** Misc
*/
Form * Intern::makeForm(std::string const & form_name, std::string const & target)
{
	Form *(*printing_form[3])(std::string const & t) = {
		&PresidentialPardonForm::printingForm,
		&ShrubberyCreationForm::printingForm,
		&RobotomyRequestForm::printingForm
	};
	std::string types_form[3] = {
		"presidential pardon",
		"shrubbery creation",
		"robotomy request"
	};
	for (int i = 0; i < 3; i++)
	{
		if (!form_name.compare(types_form[i]))
		{
			std::cout << "The intern creates a " << form_name << " form." << std::endl;
			return printing_form[i](target);
		}
	}
	throw (FormNotFoundException());
}
/*
** End of Misc
*/

/*
**  NotSignedException
*/
const char * Intern::FormNotFoundException::what() const throw()
{
	return ("the form was not found");
}
