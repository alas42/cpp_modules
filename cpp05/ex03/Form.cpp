#include "Form.hpp"

/*
** Canonical Form
*/
Form::Form(void):
	_target("John Doe"), _name("Defaut Form"), _grade_to_exec(75), _grade_to_sign(75), _is_signed(0)
{}

Form::Form(Form const & other):
	_target(other.getTarget()), _name(other.getName()), _grade_to_exec(other.getGradeToExec()), _grade_to_sign(other.getGradeToSign())
{
	*this = other;
}

Form::~Form(void)
{}

Form & Form::operator = (Form const & other)
{
	if (this == &other)
		return *this;
	this->_is_signed = other.getIsSigned();
	return *this;
}
/*
** End of Canonical Form
*/

/*
** Other Constructors
*/
Form::Form(std::string const & target, std::string const & name, int grade_to_exec, int grade_to_sign):
	_target(target), _name(name), _grade_to_exec(grade_to_exec), _grade_to_sign(grade_to_sign), _is_signed(0)
{
	if (this->getGradeToExec() < 1)
		throw(GradeTooHighException());
	else if (this->getGradeToExec() > 150)
		throw(GradeTooLowException());
	if (this->getGradeToSign() < 1)
		throw(GradeTooHighException());
	else if (this->getGradeToSign() > 150)
		throw(GradeTooLowException());
}
/*
** End of Other Constructors
*/

/*
** Misc
*/
void	Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw(Form::GradeTooLowException());
	this->_is_signed = 1;
}

void	Form::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw(Form::NotSignedException());
	else if (executor.getGrade() > this->getGradeToExec())
		throw(Form::GradeTooLowException());
	std::cout << MAGENTA << executor.getName() << " executes " << this->getName() << "." << RESET << std::endl;
	try 
	{
		this->perform(executor);
	}
	catch(std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}
/*
** End of Misc
*/

/*
** Guetters and Setters
*/
std::string const & Form::getName(void) const
{
	return this->_name;
}

std::string const & Form::getTarget(void) const
{
	return this->_target;
}

int Form::getGradeToExec(void) const
{
	return this->_grade_to_exec;
}

int Form::getGradeToSign(void) const
{
	return this->_grade_to_sign;
}

bool Form::getIsSigned(void) const
{
	return this->_is_signed;
}
/*
** End of Guetters and Setters
*/

/*
** GradeTooHighException
*/
const char * Form::GradeTooHighException::what() const throw()
{
	return ("the form's grade is too high");
}

/*
** GradeTooLowException
*/
const char * Form::GradeTooLowException::what() const throw()
{
	return ("the form's grade is too low");
}

/*
**  NotSignedException
*/
const char * Form:: NotSignedException::what() const throw()
{
	return ("the form is not signed");
}

/*
** Operator overlaod
*/
std::ostream & operator << (std::ostream & os, Form const & form)
{
	os << GREEN << form.getName() << RESET;
	if (form.getIsSigned())
		os << " is signed";
	else
		os << " is not signed";
	os << ", the grade required to sign it is " << MAGENTA << form.getGradeToSign() << RESET
		<< " and the grade required to execute it is " << MAGENTA << form.getGradeToExec() << RESET
		<< ".";
	return os;
}
