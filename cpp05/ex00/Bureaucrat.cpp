#include "Bureaucrat.hpp"

/*
** Canonical Form
*/
Bureaucrat::Bureaucrat(void): _name("John"), _grade(75)
{}

Bureaucrat::Bureaucrat(Bureaucrat const & other)
{
	*this = other;
}

Bureaucrat::~Bureaucrat(void)
{}

Bureaucrat & Bureaucrat::operator = (Bureaucrat const & other)
{
	if (this == &other)
		return *this;
	this->_grade = other.getGrade();
	return *this;
}
/*
** End of Canonical Form
*/

/*
** Other Constructors
*/
Bureaucrat::Bureaucrat(std::string const & name, int grade): _name(name)
{
	if (grade < 1)
		throw(GradeTooHighException());
	else if (grade > 150)
		throw(GradeTooLowException());
	this->_grade = grade;
}
/*
** End of Other Constructors
*/

/*
** Misc
*/
void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 1)
		throw(GradeTooHighException());
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
		throw(GradeTooLowException());
	this->_grade++;
}
void	Bureaucrat::incrementGrade(int n)
{
	if (this->_grade - n < 1)
		throw(GradeTooHighException());
	this->_grade -= n;
}

void	Bureaucrat::decrementGrade(int n)
{
	if (this->_grade + n > 150)
		throw(GradeTooLowException());
	this->_grade += n;
}
/*
** End of Misc
*/

/*
** Guetters and Setters
*/
std::string const & Bureaucrat::getName(void) const
{
	return this->_name;
}

int	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}
/*
** End of Guetters and Setters
*/

/*
** GradeTooHighException
*/
const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade is too high");
}

/*
** GradeTooLowException
*/
const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade is too low");
}

/*
** Operator overload
*/
std::ostream & operator << (std::ostream & os, Bureaucrat const & bureaucrat)
{
	os << GREEN << bureaucrat.getName() << RESET << ", bureaucrat grade " << RED << bureaucrat.getGrade() << RESET << ".";
	return os;
}
