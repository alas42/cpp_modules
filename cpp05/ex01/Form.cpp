#include "Form.hpp"

/*
** Canonical Form
*/
Form::Form(void):
	_name("defaut_form"), _grade_to_exec(75), _grade_to_sign(75), _is_signed(0)
{
	std::cout << GREEN << "Creation of a non signed Form named "
		<< this->getName() << " with grades (to exec and to sign) of " << this->getGradeToSign() << RESET << std::endl;
}

Form::Form(Form const & other):
	_name(other.getName()), _grade_to_exec(other.getGradeToExec()), _grade_to_sign(other.getGradeToSign())
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
Form::Form(std::string const & name, int grade_to_exec, int grade_to_sign):
	_name(name), _grade_to_exec(grade_to_exec), _grade_to_sign(grade_to_sign), _is_signed(0)
{
	std::cout << GREEN << "Attempting to create a non signed Form named "
		<< this->getName() << " with a grade to execute of " << this->getGradeToExec()
		<< " and a grade to sign of " << this->getGradeToSign() << RESET << std::endl;
	if (this->getGradeToExec() < 1)
		throw(GradeTooHighException());
	else if (this->getGradeToExec() > 150)
		throw(GradeTooLowException());
	if (this->getGradeToSign() < 1)
		throw(GradeTooHighException());
	else if (this->getGradeToSign() > 150)
		throw(GradeTooLowException());
	std::cout << GREEN << "Form successfully created" << RESET << std::endl;	
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
	if (this->getIsSigned())
		throw(Form::AlreadySignedException());
	this->_is_signed = 1;
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
	return ("the form' requires a lower grade");
}

/*
** GradeTooLowException
*/
const char * Form::GradeTooLowException::what() const throw()
{
	return ("the form requires a higher grade");
}

const char * Form::AlreadySignedException::what() const throw()
{
	return ("the form is already signed");
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
