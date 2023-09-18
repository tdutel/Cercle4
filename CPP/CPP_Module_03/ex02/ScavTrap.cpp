/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:15:45 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/28 13:24:46 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

	// Constructor Destructor //

ScavTrap::ScavTrap(void)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "A wild legendary appears !" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "a wild legendary " << name << " appears !" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &clapTrap)
{
	*this = clapTrap;
	std::cout << "A wild Legendary copy appears !" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "the wild Legendary disappears !" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &scavTrap)
{
	if (this != &scavTrap)
	{
		this->_name = scavTrap._name;
		this->_hitPoints = scavTrap._hitPoints;
		this->_energyPoints = scavTrap._energyPoints;
		this->_attackDamage = scavTrap._attackDamage;
	}
	return (*this);
}

	// functions //

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap has entered defensive mode !" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints >= 1 && this->_hitPoints >= 1)
	{
		this->_energyPoints--;
		std::cout << "ScavTrap "<< this->_name << " attacks " << target << ", causing " << this->_attackDamage << " of damage!" << std::endl;
	}
	else if (this->_energyPoints >= 1 )
		std::cout << "ScavTrap "<< this->_name << " can't attack, is unfortunately KO." << std::endl << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << "doesn't has enough energy to attack !" << std::endl << std::endl;
}
