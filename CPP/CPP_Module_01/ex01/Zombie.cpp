/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:25:44 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/19 17:47:06 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//	Constructor Destructor //

Zombie::Zombie()
{
}

Zombie::~Zombie(void)
{
	std::cout << "*** " << this->name << " went out with a BANG! ***" << std::endl;
}

//	Function //

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::init(std::string name)
{
	this->name = name;
}
