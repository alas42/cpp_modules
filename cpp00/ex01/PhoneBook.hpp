#ifndef	PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
    private:
		Contact _contact_array[8];
		int		_total_contact;
		void	_print_ten_char(std::string entry) const;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(void);
		void	searchContact(void) const;
};

#endif