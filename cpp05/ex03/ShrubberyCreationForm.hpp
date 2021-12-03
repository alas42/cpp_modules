#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <iostream>
# include "Form.hpp"
# include <stdexcept>
# include <fstream>

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"
# define TREE " \
                     . . .\n\
                   .        .  .     ..    .\n\
                .                 .         .  .\n\
                                .\n\
                               .                ..\n\
               .          .            .              .\n\
               .            '.,        .               .\n\
               .              'b      *\n\
                .              '$    #.                ..\n\
               .    .           $:   #:               .\n\
             ..      .  ..      *#  @):        .   . .\n\
                          .     :@,@):   ,.**:'   .\n\
              .      .,         :@@*: ..**'      .   .\n\
                       '#o.    .:(@'.@*'  .\n\
               .  .       'bq,..:,@@*'   ,*      .  .\n\
                          ,p$q8,:@)'  .p*'      .\n\
                   .     '  . '@@Pp@@*'    .  .\n\
                    .  . ..    Y7'.'     .  .\n\
                              :@):.\n\
                             .:@:'.\n\
                           .::(@:."
class ShrubberyCreationForm: public Form
{
  class OpeningShrubberyFileException: public std::exception{
		public:
			const char * what() const throw();
	};
	public :
		/*
		** Canonical Form
		*/
		ShrubberyCreationForm(void);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const & other);
		ShrubberyCreationForm & operator = (ShrubberyCreationForm const & other);

		/*
		** Other constructors
		*/
		ShrubberyCreationForm(std::string const & target);
		/*
		** Misc
		*/
		void	perform(Bureaucrat const & executor) const;
		static Form	* printingForm(std::string const & target);
		/*
		** Guetters and setters
		*/
	
};

#endif
