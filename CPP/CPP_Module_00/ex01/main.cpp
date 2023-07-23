/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:56:01 by tdutel            #+#    #+#             */
/*   Updated: 2023/04/20 11:17:47 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void) {

	PhoneBook	uL;
	std::string	command;
	int	index;
	int	i = 0;

	std::string	attribut;

	std::cout << std::endl << "~~~~~   PhoneBook ! Tap  one of the keyword bellow.   ~~~~~" << std::endl << std::endl;
	std::cout << "|>   ADD    : to add a new contact." << std::endl;
	std::cout << "|>   SEARCH : to diplay a contact." << std::endl;
	std::cout << "|>   EXIT   : to quit the program and reset all datas." << std::endl << std::endl;
	std::getline(std::cin, command);
	while (command != "EXIT" && !std::cin.eof())
	{
		while (command != "ADD" && command != "SEARCH" && command!= "EXIT" && !std::cin.eof())
		{
			std::cout << "Please enter valid command : " ;
			std::getline(std::cin, command);
		}
		if (command == "ADD")
		{
			uL.setUser(i);
			i++;
			if (i == 8)
			{
				i = 0;
			}
		}
		else if (command == "EXIT")
			break;
		else if (command == "SEARCH")
		{
			uL.getUser();
		}
		std::cout <<std::endl <<std::endl << "|>   ADD    : to add a new contact." << std::endl;
		std::cout << "|>   SEARCH : to diplay a contact." << std::endl;
		std::cout << "|>   EXIT   : to quit the program and reset all datas." << std::endl << std::endl;
		std::getline(std::cin, command);

	}
	std::cout << std::endl << "~~~~~ Program exit ~~~~~" << std::endl << std::endl;
	return (0);

}
