#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "Form.hpp"

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class Intern
{
	class FormNotFoundException: public std::exception{
		public:
			const char * what() const throw();
	};

	public :
		/*
		** Canonical Form
		*/
		Intern(void);
		~Intern(void);
		Intern(Intern const & other);
		Intern & operator = (Intern const & other);

		/*
		** Other constructors
		*/
		/*
		** Misc
		*/
		Form * makeForm(std::string const & form_name, std::string const & target);

};

#endif
