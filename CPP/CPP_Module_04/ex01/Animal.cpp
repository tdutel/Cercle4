/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:48:52 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/14 13:23:21 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

	// Constructor Destructor //

Animal::Animal(void)
{
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(const Animal &cpy)
{
	this->type = cpy.type;
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	this->type = other.type;
	std::cout << "Animal Copy assignment operator called" << std::endl;
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
	if (this->type == "Dog")
		std::cout << "Bark !" << std::endl;
	else if (this->type == "Cat")
		std::cout << "Meow !" << std::endl;
	else
		std::cout << "*unknown cry*" << std::endl;
}
