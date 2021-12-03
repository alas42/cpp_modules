#include "Bureaucrat.hpp"

/*
** Canonical Form
*/
Bureaucrat::Bureaucrat(void): _name("John"), _grade(75)
{
	std::cout << GREEN << "Creation of a Bureaucrat named "
		<< this->getName() << " with a grade of " << this->getGrade() << RESET << std::endl;
}

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
	std::cout << GREEN << "Attempting to create a Bureaucrat named "
		<< this->getName() << " with a grade of " << grade << RESET << std::endl;
	if (grade < 1)
		throw(GradeTooHighException());
	else if (grade > 150)
		throw(GradeTooLowException());
	this->_grade = grade;
	std::cout << GREEN << "Bureaucrat successfully created "<< RESET << std::endl;
}
/*
** End of Other Constructors
*/

/*
** Misc
*/
void	Bureaucrat::incrementGrade(void)
{
	std::cout << MAGENTA << "Attempting to increment(1) the grade of " << this->getName() << RESET << std::endl;
	if (this->_grade - 1 < 1)
		throw(GradeTooHighException());
	this->_grade--;
	std::cout << MAGENTA << "Incrementation successful" << RESET << std::endl;
}

void	Bureaucrat::decrementGrade(void)
{
	std::cout << MAGENTA << "Attempting to decrement(1) the grade of " << this->getName() << RESET << std::endl;
	if (this->_grade + 1 > 150)
		throw(GradeTooLowException());
	this->_grade++;
	std::cout << MAGENTA << "Decrementation successful" << RESET << std::endl;
}
void	Bureaucrat::incrementGrade(int n)
{
	std::cout << MAGENTA << "Attempting to increment(" << n << ") the grade of " << this->getName() << RESET << std::endl;
	if (this->_grade - n < 1)
		throw(GradeTooHighException());
	this->_grade -= n;
	std::cout << MAGENTA << "Incrementation successful" << RESET << std::endl;
}

void	Bureaucrat::decrementGrade(int n)
{
	std::cout << MAGENTA << "Attempting to decrement(" << n << ") the grade of " << this->getName() << RESET << std::endl;
	if (this->_grade + n > 150)
		throw(GradeTooLowException());
	this->_grade += n;
	std::cout << MAGENTA << "Decrementation successful" << RESET << std::endl;
}

void	Bureaucrat::signForm(Form & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signs " << form.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << this->getName() << " cannot sign " << form.getName() << " because "
			<< e.what() << "." << RESET << std::endl;
	}
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
	return ("The bureaucrat's grade is too high");
}

/*
** GradeTooLowException
*/
const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The bureaucrat's grade is too low");
}

/*
** Operator overload
*/
std::ostream & operator << (std::ostream & os, Bureaucrat const & bureaucrat)
{
	os << GREEN << bureaucrat.getName() << RESET << ", bureaucrat grade " << MAGENTA << bureaucrat.getGrade() << RESET << ".";
	return os;
}
