#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <cstdlib>

class PhoneBook
{
    private:
		Contact 	_contact_array[8];
		int			_total_contact;
		std::string	_print_ten_char(std::string entry) const;
		std::string	_readingIn(std::string prompt, std::string to_fill) const;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(void);
		void	searchContact(void) const;
};

#endif