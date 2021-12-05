#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

# include <string>
# include <iostream>

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class Template
{
	public :
		/*
		** Canonical Form
		*/
		Template(void);
		~Template(void);
		Template(Template const & other);
		Template & operator = (Template const & other);

		/*
		** Other constructors
		*/
		/*
		** Misc
		*/
		/*
		** Guetters and setters
		*/
	private :
	
};

#endif
