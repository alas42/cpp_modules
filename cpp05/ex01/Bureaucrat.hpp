#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Form.hpp"

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class Form;

class Bureaucrat
{
	class GradeTooHighException: public std::exception{
		public:
			const char * what() const throw();
	};
	class GradeTooLowException: public std::exception{
		public:
			const char * what() const throw();
	};
	public :
		/*
		** Canonical Form
		*/
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(Bureaucrat const & other);
		Bureaucrat & operator = (Bureaucrat const & other);

		/*
		** Other constructors
		*/
		Bureaucrat(std::string const & name, int grade);

		/*
		** Misc
		*/
		void	incrementGrade();
		void	decrementGrade();
		void	incrementGrade(int n);
		void	decrementGrade(int n);
		void	signForm(Form & form);
	
		/*
		** Guetters and setters
		*/
		std::string const & getName() const;
		int					getGrade() const;

	private :
		std::string const 	_name;
		int					_grade;
};

std::ostream & operator << (std::ostream & os, Bureaucrat const & bureaucrat);

#endif
