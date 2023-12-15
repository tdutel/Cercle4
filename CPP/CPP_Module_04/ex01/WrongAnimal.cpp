/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:38:52 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/15 12:40:01 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

	// Constructor Destructor //

WrongAnimal::WrongAnimal(void)
{
	std::cout << "\x1b[32mWrongAnimal Constructor called\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy)
{
	this->type = cpy.type;
	std::cout << "\x1b[32mWrongAnimal Copy constructor called\033[0m" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\x1b[32mAnimal Destructor called\033[0m" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	this->type = other.type;
	std::cout << "\x1b[32mWrongAnimal Copy assignment operator called\033[0m" << std::endl;
	return (*this);
}

void	WrongAnimal::setType(std::string type)
{
	this->type = type;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "\x1b[35m*wrong unknown cry*\033[0m" << std::endl;
}
