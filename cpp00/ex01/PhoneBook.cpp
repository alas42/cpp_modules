#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_total_contact = 0;
}

PhoneBook::~PhoneBook(void)
{}

std::string	PhoneBook::_readingIn(std::string prompt, std::string to_fill) const
{
	std::cout << prompt << std::endl;
	std::getline(std::cin, to_fill);
	if(std::cin.eof())
		std::cin.clear();
	return (to_fill);
}

void	PhoneBook::addContact()
{
	std::string contact_infos[5];
	std::string	confirmation;
	int			i;

	i = 0;
	if (this->_total_contact >= 8)
	{
		std::cout << "\nWarning : Contact list is FULL, adding one will erase the oldest entry:\n"
			<< "If you want to go back, enter [BACK] now" << std::endl;
		std::getline(std::cin, confirmation);
		if(std::cin.eof())
			std::cin.clear();
		if (!confirmation.compare("BACK"))
			return ;
	}
	std::cout << "\nPlease enter the following data:" << std::endl;

	while (contact_infos[0].empty())
		contact_infos[0] = this->_readingIn("First Name:", contact_infos[0]);
	while (contact_infos[1].empty())
		contact_infos[1] = this->_readingIn("Last Name:", contact_infos[1]);
	while (contact_infos[2].empty())
		contact_infos[2] = this->_readingIn("Nickname:", contact_infos[2]);
	while (contact_infos[3].empty())
		contact_infos[3] = this->_readingIn("Phone Number:", contact_infos[3]);
	while (contact_infos[4].empty())
		contact_infos[4] = this->_readingIn("Darkest Secret:", contact_infos[4]);

	this->_contact_array[this->_total_contact % 8].setInfos(contact_infos[0],
		contact_infos[1], contact_infos[2], contact_infos[3], contact_infos[4]);
	this->_total_contact++;
}

std::string	PhoneBook::_print_ten_char(std::string entry) const
{
	if (entry.size() < 10)
	{
		while (entry.size() < 10)
		{
			entry = entry.insert(0, " ");
		}
	}
	else if (entry.size() > 10)
	{
		entry = entry.insert(9, ".");
		entry = entry.substr(0, 10);
	}
	return entry;
}

void	PhoneBook::searchContact() const
{
	int			i;
	int			index = -1;
	std::string	getline_index;

	i = 1;
	if (this->_total_contact == 0)
	{
		std::cout << "There is no contact yet in The PhoneBook" << std::endl;
		return ;
	}

	std::cout << "     index|first name| last name|  nickname" << std::endl;
	std::cout << "___________________________________________" << std::endl;
	while (i < 9 && !this->_contact_array[i - 1].getFirstName().empty())
	{
		std::cout << "         " << i 
		<< "|" << this->_print_ten_char(this->_contact_array[i - 1].getFirstName())
		<< "|" << this->_print_ten_char(this->_contact_array[i - 1].getLastName())
		<< "|" << this->_print_ten_char(this->_contact_array[i - 1].getNickname())
		<< std::endl;
		i++;
	}

	while (index < 1 || index > this->_total_contact)
	{
		std::cout << "\n\nContact index to retrieve information:" << std::endl;
		std::getline(std::cin, getline_index);
		if(std::cin.eof())
			std::cin.clear();
		index = atoi(getline_index.c_str());
		if (index > 8)
			index = 0;
	}
	std::cout << "First Name: " << this->_contact_array[index - 1].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->_contact_array[index - 1].getLastName()  << std::endl;
	std::cout << "Nickname: " << this->_contact_array[index - 1].getNickname()  << std::endl;
	std::cout << "Phone Number: " << this->_contact_array[index - 1].getPhoneNumber()  << std::endl;
	std::cout << "Darkest Secret: " << this->_contact_array[index - 1].getDarkestSecret()  << std::endl;
}

int	main(void)
{
	int			ret;
	std::string key_word[3];
	std::string	input;
	PhoneBook	the_phonebook;

	std::cout << "***** HELLO AND WELCOME TO THE PHONEBOOK *****\n\n"
		<< "Please enter one of the following three actions:" << std::endl;
	key_word[0] = "EXIT";
	key_word[1] = "SEARCH";
	key_word[2] = "ADD";
	ret = 0;
	while (!ret)
	{
		std::cout << "[EXIT | ADD | SEARCH]" << std::endl;
		std::getline(std::cin, input);
		if(std::cin.eof())
			std::cin.clear();
		if (!input.compare(key_word[0]))
		{
			std::cout << "Goodbye!" << std::endl;
			ret = 1;
		}
		if (!input.compare(key_word[1]))
			the_phonebook.searchContact();
		else if (!input.compare(key_word[2]))
			the_phonebook.addContact();
	}
	return (0);
}