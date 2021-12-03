#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <iostream>
# include "Form.hpp"
# include <stdexcept>
# include <cstdlib>
# include <ctime>

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class RobotomyRequestForm: public Form
{
	class RobotomyFailedException: public std::exception{
		public:
			const char * what() const throw();
	};
	public :
		/*
		** Canonical Form
		*/
		RobotomyRequestForm(void);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const & other);
		RobotomyRequestForm & operator = (RobotomyRequestForm const & other);

		/*
		** Other constructors
		*/
		RobotomyRequestForm(std::string const & target);
		/*
		** Misc
		*/
		void	perform(Bureaucrat const & executor) const;
		/*
		** Guetters and setters
		*/
	
};

#endif
