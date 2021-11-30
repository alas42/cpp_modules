#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include <iostream>
# include "Form.hpp"
# include <stdexcept>

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class PresidentialPardonForm: public Form
{
	public :
		/*
		** Canonical Form
		*/
		PresidentialPardonForm(void);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const & other);
		PresidentialPardonForm & operator = (PresidentialPardonForm const & other);

		/*
		** Other constructors
		*/
		PresidentialPardonForm(std::string const & target);
		/*
		** Misc
		*/
		void	perform(Bureaucrat const & executor) const;
		/*
		** Guetters and setters
		*/
	
};

#endif
