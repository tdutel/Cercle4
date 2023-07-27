/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:36:02 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/27 15:34:21 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

	// Constructor Destructor //

ClapTrap::ClapTrap(void )
{
	std::cout << "Unnown, GO !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	*this = clapTrap;
	std::cout << "Ditto, GO !" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << _name << ", GO !" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << _name << ", come back !" << std::endl;
}

	// get set //

void	ClapTrap::setHitPoints(int n)
{
	_hitPoints = n;
}

void	ClapTrap::setEnergyPoints(int n)
{
	_energyPoints = n;
}

void	ClapTrap::setAttackDamage(int n)
{
	_attackDamage = n;
}

void	ClapTrap::setStats(int attack, int energy, int hp)
{
	this->setAttackDamage(attack);
	this->setEnergyPoints(energy);
	this->setHitPoints(hp);
	
}

std::string	ClapTrap::getName(void)
{
	return (this->_name);
}

int	ClapTrap::getAttackDamage(void)
{
	return (this->_attackDamage);
}

int	ClapTrap::getEnergyPoints(void)
{
	return (this->_energyPoints);
}

int	ClapTrap::getHitPoints(void)
{
	return (this->_hitPoints);
}


	// Functions //

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints >= 1 && this->_hitPoints >= 1)
	{
		this->_energyPoints--;
		std::cout << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " of damage!" << std::endl;
	}
	else if (this->_energyPoints >= 1 )
		std::cout << this->_name << " can't attack, is unfortunately KO." << std::endl << std::endl;
	else
		std::cout << this->_name << "doesn't has enough energy to attack !" << std::endl << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	std::cout << "\n	Its very effective ! " << this->_name << " lost " << amount << " HP ! He has now ";
	if (this->_hitPoints <= 0) {
		std::cout << "0 HP." << std::endl << std::endl;
		std::cout << this->_name << " has just died !" << std::endl;
	}
	else
		std::cout << this->_hitPoints << " HP." << std::endl << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints >= 1 && this->_hitPoints >= 1)
	{
		this->_energyPoints--;
		std::cout << this->_name << " restore " << amount <<" HP.";
		this->_hitPoints += amount;
		std::cout << " He has now " << this->_hitPoints << " HP !" << std::endl;
	}
	else if (this->_energyPoints >= 1 )
		std::cout << this->_name << " can't be repaired, is unfortunately KO." << std::endl << std::endl;
	else
		std::cout << this->_name << "doesn't has enough energy to be repaired !" << std::endl << std::endl;
	
}


	// operator //

ClapTrap	&ClapTrap::operator=(const ClapTrap &clapTrap)
{
	if (this != &clapTrap)
	{
		this->_name = clapTrap._name;
		this->_hitPoints = clapTrap._hitPoints;
		this->_energyPoints = clapTrap._energyPoints;
		this->_attackDamage = clapTrap._attackDamage;
	}
	return (*this);
}
