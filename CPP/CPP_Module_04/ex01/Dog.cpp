/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:56:59 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/15 11:45:08 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

	// Constructor Destructor //

Dog::Dog(void)
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "\x1b[31mDog Constructor called\033[0m" << std::endl;
}

Dog::Dog(const Dog &cpy) : Animal(cpy)
{
	this->type = cpy.type;
	this->brain = new Brain(*cpy.brain);
	std::cout << "\x1b[31mDog Copy Constructor called\033[0m" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "\x1b[31mDog Destructor called\033[0m" << std::endl;
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
	std::cout << "\x1b[31mDog Copy assignment operator called\033[0m" << std::endl;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "\x1b[31mBark !\033[0m" << std::endl;
}
