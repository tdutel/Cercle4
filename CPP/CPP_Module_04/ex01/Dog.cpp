/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:56:59 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/14 13:57:37 by tdutel           ###   ########.fr       */
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
	this->brain = new Brain();
	*this->brain = *cpy.brain;
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog Destructor called" << std::endl;
}

void	Dog::setIdeas(std::string ideas, int i)
{
		this->brain->setIdeas(ideas, i);
}

std::string	Dog::getIdeas(int i) const
{
	return (this->brain->getIdeas(i));
}


Dog &Dog::operator=(const Dog& other)
{
	this->type = other.type;
	(this->brain) = (other.brain);
	std::cout << "Dog Copy assignment operator called" << std::endl;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Bark !" << std::endl;
}
