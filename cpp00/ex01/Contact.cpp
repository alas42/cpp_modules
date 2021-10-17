#include "Contact.hpp"

Contact::Contact(void)
{}

Contact::~Contact(void)
{}

std::string Contact::getFirstName(void) const
{
	return (this->_first_name);
}

std::string Contact::getLastName(void) const
{
	return (this->_last_name);
}

std::string Contact::getNickname(void) const
{
	return (this->_nickname);
}

std::string Contact::getPhoneNumber(void) const
{
	return (this->_phone_number);
}

std::string Contact::getDarkestSecret(void) const
{
	return (this->_darkest_secret);
}

void		Contact::_setFirstName(std::string f_n)
{
	this->_first_name = f_n;
}

void		Contact::_setLastName(std::string l_n)
{
	this->_last_name = l_n;
}

void		Contact::_setNickname(std::string n_n)
{
	this->_nickname = n_n;
}

void		Contact::_setPhoneNumber(std::string p_n)
{
	this->_phone_number = p_n;
}

void		Contact::_setDarkestSecret(std::string d_s)
{
	this->_darkest_secret = d_s;
}

void		Contact::setInfos(std::string first_name, std::string last_name,
				std::string nickname, std::string phone_number,
				std::string darkest_secret)
{
	this->_setFirstName(first_name);
	this->_setLastName(last_name);
	this->_setNickname(nickname);
	this->_setPhoneNumber(phone_number);
	this->_setDarkestSecret(darkest_secret);
}
