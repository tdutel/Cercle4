/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:56:59 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/12 12:35:43 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

	// Constructor Destructor //

Dog::Dog(void)
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog &cpy) : Animal(cpy)
{
	this->type = "Dog";
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& other)
{
	this->type = other.type;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}
