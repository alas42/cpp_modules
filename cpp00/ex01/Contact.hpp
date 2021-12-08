#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
    private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
		void		_setFirstName(std::string f_n);
		void		_setLastName(std::string l_n);
		void		_setNickname(std::string n_n);
		void		_setPhoneNumber(std::string p_n);
		void		_setDarkestSecret(std::string d_s);

	public:
		Contact();
		~Contact(void);
		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickname(void) const;
		std::string getPhoneNumber(void) const;
		std::string getDarkestSecret(void) const;
		void		setInfos(std::string first_name, std::string last_name,
						std::string nickname, std::string phone_number,
						std::string darkest_secret);
};

#endif
