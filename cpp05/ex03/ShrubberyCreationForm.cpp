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
	ofs << TREE;
	ofs << executor.getName();
	ofs.close();
}

Form	* ShrubberyCreationForm::printingForm(std::string const & target)
{
	return new ShrubberyCreationForm(target);
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
