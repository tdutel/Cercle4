/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:48:52 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/15 13:18:30 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

	// Constructor Destructor //

Animal::Animal(void)
{
	std::cout << "\x1b[32mAnimal Constructor called\033[0m" << std::endl;
}

Animal::Animal(const Animal &cpy)
{
	this->type = cpy.type;
	std::cout << "\x1b[32mAnimal Copy constructor called\033[0m" << std::endl;
}

Animal::~Animal()
{
	std::cout << "\x1b[32mAnimal Destructor called\033[0m" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	this->type = other.type;
	std::cout << "\x1b[32mAnimal Copy assignment operator called\033[0m" << std::endl;
	return (*this);
}

void	Animal::setType(std::string type)
{
	this->type = type;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

void Animal::makeSound(void) const
{
	std::cout << "\x1b[35m*unknown cry*\033[0m" << std::endl;
}
