/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:45:38 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/06 15:18:39 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

	// Constructor Destructor //

FragTrap::FragTrap(void)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "A MYTHICAL appears ! (FragTrap constructor called)" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "A MYTHICAL " << name << " appears ! (FragTrap constructor called)" << std::endl;
}

FragTrap::FragTrap(const FragTrap &clapTrap)
{
	*this = clapTrap;
	std::cout << "A MYTHICAL copy appears ! (FragTrap constructor copy called)" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "the MYTHICAL disappears ! (FragTrap destructor called)" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &fragTrap)
{
	if (this != &fragTrap)
	{
		this->_name = fragTrap._name;
		this->_hitPoints = fragTrap._hitPoints;
		this->_energyPoints = fragTrap._energyPoints;
		this->_attackDamage = fragTrap._attackDamage;
	}
	return (*this);
}

	// functions //

void FragTrap::guardGate()
{
	std::cout << "FragTrap " << this->_name <<" entered defensive mode !" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_energyPoints >= 1 && this->_hitPoints >= 1)
	{
		this->_energyPoints--;
		std::cout << "FragTrap "<< this->_name << " attacks " << target << ", causing " << this->_attackDamage << " of damage!" << std::endl;
	}
	else if (this->_energyPoints >= 1 )
		std::cout << "FragTrap "<< this->_name << " can't attack, is unfortunately KO." << std::endl << std::endl;
	else
		std::cout << "FragTrap " << this->_name << "doesn't has enough energy to attack !" << std::endl << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	// std::string command;

	std::cout << "FragTrap " << this->_name << " give you an high fives !" << std::endl << std::endl;
	// std::cout << "FragTrap " << this->_name << " want to be your friend ! would you be their friend ? ('Yes' or 'No')" << std::endl;
	// std::getline(std::cin, command);
	// if (command == "Yes")
	// 	{
	// 		std::cout << this->_name << " is happy to hear it :D" << std::endl;
	// 	}
	// else
	// 	{
	// 		std::cout << this->_name << " don't understand and use Draco Meteor. It's very effective, you lost 180 HP." << std::endl;
	// 		std::cout << std::endl << "You just died :O" << std::endl;
	// 	}
}
