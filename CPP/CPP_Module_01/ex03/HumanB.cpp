/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:51:06 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/20 12:25:47 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

//	Constructor Destructor //

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_Weapon = NULL;
}

HumanB::~HumanB(void)
{
	
}

//	Function //

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_Weapon = &weapon;
}

void HumanB::attack(void)
{
	if (this->_Weapon)
		std::cout << this->_name << " attacks with their " << this->_Weapon->getType() << std::endl;
	else
		std::cout << this->_name << " is unarmed" << std::endl;
}

