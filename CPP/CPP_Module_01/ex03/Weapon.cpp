/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:15:35 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/20 12:09:15 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//	Constructor Destructor //

Weapon::Weapon(std::string type)
{
	this->setType(type);
}

Weapon::~Weapon(void)
{
	
}

//	Function //

void	Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string	&Weapon::getType(void) const
{
	// const std::string	&tmp = this->type;
	return (this->type);
}
