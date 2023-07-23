/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:45:08 by tdutel            #+#    #+#             */
/*   Updated: 2023/04/20 11:02:06 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) : _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret("")
{
}

Contact::~Contact(void)
{
}


// Set Attribut //

void Contact::setFirstName(std::string FirstName)
{
	this->_firstName = FirstName;
}

void Contact::setLastName(std::string LastName)
{
	this->_lastName = LastName;
}

void Contact::setNickname(std::string Nickname)
{
	this->_nickname = Nickname;
}

void Contact::setPhoneNumber(std::string PhoneNumber)
{
	this->_phoneNumber = PhoneNumber;
}

void Contact::setDarkestSecret(std::string DarkestSecret)
{
	this->_darkestSecret = DarkestSecret;
}


// Get Attribut //

std::string Contact::getFirstName() const
{
	return (this->_firstName);
}

std::string Contact::getLastName() const
{
	return (this->_lastName);
}

std::string Contact::getNickname() const
{
	return (this->_nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (this->_darkestSecret);
}
