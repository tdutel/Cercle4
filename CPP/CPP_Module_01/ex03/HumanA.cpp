/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:26:30 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/20 12:23:21 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//	Constructor Destructor //

HumanA::HumanA(std::string name, Weapon &Weapon) : _name(name),	 _Weapon(Weapon)
{
}

HumanA::~HumanA(void)
{
	
}

//	Function //

void HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_Weapon.getType() << std::endl;
}
