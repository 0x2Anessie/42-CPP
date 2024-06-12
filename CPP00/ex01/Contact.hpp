#pragma once
#include <iostream>

/*
	Contact
	- On definit les attributs d'un contact
	- On definit les getters et setters pour chaque attribut
*/
class contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _secret;
	public:
		std::string		getFirstName() const;
		std::string		getLastName() const;
		std::string		getNickname() const;
		std::string		getPhoneNumber() const;
		std::string		getDarkestSecret() const;
		void	setFirstName(std::string newfirstname);
		void	setLastName(std::string newlastname);
		void	setNickname(std::string newnickname);
		void	setPhoneNumber(std::string newphonenumber);
		void	setDarkestSecret(std::string newsecret);
		contact();
		~contact();
};
