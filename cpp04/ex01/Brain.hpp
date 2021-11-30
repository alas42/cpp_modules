#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class Brain
{
	public :
		/*
		** Canonical Form
		*/
		Brain(void);
		~Brain(void);
		Brain(Brain const & other);
		Brain & operator = (Brain const & other);

		/*
		** Other constructors
		*/
		/*
		** Misc
		*/
		/*
		** Guetters and setters
		*/
		std::string const & getIdeaX(int const x) const;
		void setIdeaX(int const x, std::string const & str);

	private :
		std::string ideas[100];
};
#endif
