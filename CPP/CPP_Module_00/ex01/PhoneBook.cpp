/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:15:06 by tdutel            #+#    #+#             */
/*   Updated: 2023/04/20 16:27:54 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook(void)
{
}

int	PhoneBook::checkAttribut(std::string attribut)
{
	int	i;

	i = 0;
	while (i < attribut.size())
	{
		if (attribut[i] == '\t')
			return (1);
		i++;
	}
	i = 0;
	while (attribut[i] == ' ')
		i++;
	if (i == attribut.size())
		return (1);
	return (0);
}

void PhoneBook::setUser(int	i)
{
	std::string	attribut;

	std::cout << std::endl << "~~~~~ Adding new contact ~~~~~" << std::endl << std::endl;
			std::cout << "First name : ";
			while (attribut.empty() || checkAttribut(attribut) == 1)
			{
				std::getline(std::cin, attribut);
			}
			this->_userList[i].setFirstName(attribut);

			std::cout << std::endl << "Last name : ";
			std::getline(std::cin, attribut);
			while (attribut.empty() || checkAttribut(attribut) == 1)
			{
				std::getline(std::cin, attribut);
			}
			this->_userList[i].setLastName(attribut);

			std::cout << std::endl << "Nickname : ";
			std::getline(std::cin, attribut);
			while (attribut.empty() || checkAttribut(attribut) == 1)
			{
				std::getline(std::cin, attribut);
			}
			this->_userList[i].setNickname(attribut);

			std::cout << std::endl << "Phone number : ";
			std::getline(std::cin, attribut);
			while (attribut.empty())
			{
				std::getline(std::cin, attribut);
			}
			while (attribut.size() != 10 || (attribut.find_first_not_of("0123456789") < 10))
			{
				std::cout << "Please enter a valid number : ";
				std::getline(std::cin, attribut);
			}
			this->_userList[i].setPhoneNumber(attribut);

			std::cout << std::endl << "Darkest secret : ";
			std::getline(std::cin, attribut);
			while (attribut.empty() || checkAttribut(attribut) == 1)
			{
				std::getline(std::cin, attribut);
			}
			this->_userList[i].setDarkestSecret(attribut);

			std::cout <<std::endl << "~~~~~ New contact added ~~~~~" << std::endl;
}

std::string PhoneBook::displayAttribut(std::string attribut)
{
	if (attribut.size() > 10)
	{
		attribut.resize(9);
		attribut.resize(attribut.size()+1, '.');
	}
	return (attribut);
}

std::string PhoneBook::checkEmpty(Contact user, std::string attribut)
{
	if (user.getPhoneNumber() == "")
		return("(empty)");
	return (attribut);
}

void PhoneBook::displayDetails(Contact user)
{
	std::cout << std::endl << "First name     : " << checkEmpty(user, user.getFirstName()) << std::endl;
	std::cout << "Latst name     : " << checkEmpty(user, user.getLastName()) << std::endl;
	std::cout << "Nickname       : " <<  checkEmpty(user, user.getNickname()) << std::endl;
	std::cout << "Phone number   : " << checkEmpty(user, user.getPhoneNumber()) << std::endl;			//faire une fonction comme display attribut qui verifie si cest nul pour afficher "null" ou empty//
	std::cout << "Darkest secret : " << checkEmpty(user, user.getDarkestSecret()) << std::endl;
}


void PhoneBook::getUser()
{
	std::string	index;

	std::cout << std::endl << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10) << "firstName" << "|" << std::setw(10) << "lastName" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|" << std::setw(10) << displayAttribut(this->_userList[i].getFirstName()) << "|" << std::setw(10) << displayAttribut(this->_userList[i].getLastName()) << "|" << std::setw(10) << displayAttribut(this->_userList[i].getNickname()) << "|" << std::endl;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << std::endl << "tap index number to see associated contact : ";
	std::getline(std::cin, index);
	while ((index.size() != 1|| (index.find_first_not_of("01234567") < 10)) && !std::cin.eof())
			{
				std::cout << std::endl << "Please enter a valid number : ";
				std::getline(std::cin, index);
			}
			if (std::cin.eof())
				return ;
	displayDetails(this->_userList[std::stoi(index)]);
}
