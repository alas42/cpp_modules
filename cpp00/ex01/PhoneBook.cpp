#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_total_contact = 0;
}

PhoneBook::~PhoneBook(void)
{}

void	PhoneBook::addContact()
{
	std::string contact_infos[5];
	int			i;

	i = 0;
	std::cout << "\nPlease enter the following data:\n";
	while (contact_infos[0].empty())
	{
		std::cout << "First Name:\n";
		std::cin >> contact_infos[0];
		std::cout << "\n";
	}
	while (contact_infos[1].empty())
	{
		std::cout << "Last Name:\n";
		std::cin >> contact_infos[1];
		std::cout << "\n";
	}
	while (contact_infos[2].empty())
	{
		std::cout << "Nickname:\n";
		std::cin >> contact_infos[2];
		std::cout << "\n";
	}
	while (contact_infos[3].empty())
	{
		std::cout << "Phone Number:\n";
		std::cin >> contact_infos[3];
		std::cout << "\n";
	}
	while (contact_infos[4].empty())
	{
		std::cout << "Darkest Secret:\n";
		std::cin >> contact_infos[4];
		std::cout << "\n";
	}
	this->_contact_array[this->_total_contact % 8].setInfos(contact_infos[0], contact_infos[1], contact_infos[2], contact_infos[3], contact_infos[4]);
	this->_total_contact++;
}

void	PhoneBook::_print_ten_char(std::string entry) const
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
	std::cout << entry;
}

void	PhoneBook::searchContact() const
{
	int	i;
	int	index;

	i = 0;
	index = -1;
	if (this->_total_contact == 0)
	{
		std::cout << "There is no contact yet in The PhoneBook\n";
		return ;
	}
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	std::cout << "___________________________________________" << std::endl;
	while (i < 8 && !this->_contact_array[i].getFirstName().empty())
	{
		std::cout << "         " << i << "|";
		this->_print_ten_char(this->_contact_array[i].getFirstName());
		std::cout << "|";
		this->_print_ten_char(this->_contact_array[i].getLastName());
		std::cout << "|";
		this->_print_ten_char(this->_contact_array[i].getNickname());
		std::cout << "\n";
		i++;
	}
	while (index < 0 || index >= this->_total_contact)
	{
		std::cout << "\n\nContact index to retrieve information:\n";
		std::cin >> index;
	}
	std::cout << "First Name: " << this->_contact_array[index].getFirstName() << "\n";
	std::cout << "Last Name: " << this->_contact_array[index].getLastName() << "\n";
	std::cout << "Nickname: " << this->_contact_array[index].getNickname() << "\n";
	std::cout << "Phone Number: " << this->_contact_array[index].getPhoneNumber() << "\n";
	std::cout << "Darkest Secret: " << this->_contact_array[index].getDarkestSecret() << "\n\n";
}

int	main(void)
{
	int			ret;
	std::string key_word[3];
	std::string	input;
	PhoneBook	the_phonebook;

	std::cout << "***** HELLO AND WELCOME TO THE PHONEBOOK *****\n\n";
	std::cout << "Please enter one of the following three actions:\n\n";
	key_word[0] = "EXIT";
	key_word[1] = "SEARCH";
	key_word[2] = "ADD";
	ret = 0;
	while (ret == 0)
	{
		std::cout << "[EXIT | ADD | SEARCH]\n";
		std::cin >> input;
		if (!input.compare(key_word[1]))
		{
			the_phonebook.searchContact();
		}
		else if (!input.compare(key_word[2]))
		{
			the_phonebook.addContact();
		}
		else if (!input.compare(key_word[0]))
		{
			std::cout << "Goodbye!" << std::endl;
			ret = 1;
		}
	}
	return (0);
}