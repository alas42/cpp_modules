#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class Bureaucrat;

class Form
{
	class GradeTooHighException: public std::exception{
		public:
			const char * what() const throw();
	};
	class GradeTooLowException: public std::exception{
		public:
			const char * what() const throw();
	};
	class NotSignedException: public std::exception{
		public:
			const char * what() const throw();
	};
	class AlreadySignedException: public std::exception{
		public:
			const char * what() const throw();
	};
	public :
		/*
		** Canonical Form
		*/
		Form(void);
		virtual ~Form(void);
		Form(Form const & other);
		Form & operator = (Form const & other);

		/*
		** Other constructors
		*/
		Form(std::string const & target, std::string const & name, int grade_to_sign, int grade_to_exec);

		/*
		** Misc
		*/
		void	beSigned(Bureaucrat const & bureaucrat);
		void	execute(Bureaucrat const & executor) const;
		virtual void	perform(Bureaucrat const & executor) const = 0;

		/*
		** Guetters and setters
		*/
		int		getGradeToExec(void) const;
		int		getGradeToSign(void) const;
		std::string const & getTarget(void) const;
		std::string const & getName(void) const;
		bool	getIsSigned(void) const;

	private :
		std::string const	_target;
		std::string const	_name;
		int const			_grade_to_exec;
		int const			_grade_to_sign;
		bool				_is_signed;
};

std::ostream & operator << (std::ostream & os, Form const & form);

#endif
