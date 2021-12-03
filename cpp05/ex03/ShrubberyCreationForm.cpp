#include "ShrubberyCreationForm.hpp"

/*
** Canonical Form
*/
ShrubberyCreationForm::ShrubberyCreationForm(void): Form("John Doe", "shrubbery creation", 137, 145)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other): Form(other)
{
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}

ShrubberyCreationForm & ShrubberyCreationForm::operator = (ShrubberyCreationForm const & other)
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
ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target): Form(target, "shrubbery creation", 137, 145)
{}
/*
** End of Other Constructors
*/

/*
** Misc
*/
void	ShrubberyCreationForm::perform(Bureaucrat const & executor) const
{
	std::ofstream ofs;
	std::string outfile(this->getTarget() + "_shrubbery");
	ofs.open(outfile.c_str(), std::ios::trunc);
	if (ofs.is_open())
	{
		ofs << TREE;
		ofs << executor.getName();
		ofs.close();
	}
	else
		throw (OpeningShrubberyFileException());
}

Form	* ShrubberyCreationForm::printingForm(std::string const & target)
{
	return new ShrubberyCreationForm(target);
}
/*
** End of Misc
*/

const char * ShrubberyCreationForm::OpeningShrubberyFileException::what() const throw()
{
	return ("The Shrubbery file could not be opened.");
}

/*
** Guetters and Setters
*/
/*
** End of Guetters and Setters
*/
