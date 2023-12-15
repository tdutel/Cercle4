/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:17:38 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/15 11:59:53 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

	// Constructor Destructor //

Cat::Cat(void)
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "\x1B[34mCat Constructor called\033[0m" << std::endl;
}

Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	this->type = cpy.type;
	this->brain = new Brain(*cpy.brain);
	std::cout << "\x1B[34mCat Constructor called\033[0m" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "\x1B[34mCat Destructor called\033[0m" << std::endl;
}

void	Cat::setIdeas(std::string ideas, int i)
{
		this->brain->setIdeas(ideas, i);
}

std::string	Cat::getIdeas(int i) const
{
	return (this->brain->getIdeas(i));
}


Cat &Cat::operator=(const Cat& other)
{
	this->type = other.type;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "\x1B[34mMeow !\033[0m" << std::endl;
}
