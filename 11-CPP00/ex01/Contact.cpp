#include "Contact.hpp"

contact::contact()
{
	//std::cout << "contact created" << std::endl;
}

contact::~contact()
{
	//std::cout << "contact deleted" << std::endl;
}

// Getters
std::string		contact::getFirstName() const
{
	return(_firstName);
}

std::string		contact::getLastName() const
{
	return(_lastName);
}

std::string		contact::getNickname() const
{
	return(_nickname);
}

std::string		contact::getPhoneNumber() const
{
	return(_phoneNumber);
}

std::string		contact::getDarkestSecret() const
{
	return(_secret);
}

// Setters
void	contact::setFirstName(std::string newfirstname)
{
	_firstName = newfirstname;
}

void	contact::setLastName(std::string newlastname)
{
	_lastName = newlastname;
}
void	contact::setNickname(std::string newnickname)
{
	_nickname = newnickname;
}

void	contact::setPhoneNumber(std::string newphonenumber)
{
	_phoneNumber = newphonenumber;
}

void	contact::setDarkestSecret(std::string newsecret)
{
	_secret = newsecret;
}

