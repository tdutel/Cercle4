/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:14:37 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/21 13:28:29 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

	// Constructor Destructor	//
Harl::Harl()
{
}

Harl::~Harl()
{
}

	// Functions //

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	void (Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string array = "DEBUG,INFO,WARNING,ERROR";

	switch (array.find(level))
	{
	case (0):
		(this->*ptr[0])();
		break;
	case (6):
		(this->*ptr[1])();
		break;
	case (11):
		(this->*ptr[2])();
		break;
	case (19):
		(this->*ptr[3])();
		break;
	default:
		std::cout << "unknown argument" << std::endl;
		break;
	}
}
