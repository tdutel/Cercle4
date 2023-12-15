/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:17:38 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/11 13:29:15 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

	// Constructor Destructor //

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	this->brain = new Brain();
	std::cout << "\x1B[34mWrongCat Constructor called\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cpy) : WrongAnimal(cpy)
{
	this->type = cpy.type;
	this->brain = new Brain(*cpy.brain);
	std::cout << "\x1B[34mWrongCat Constructor called\033[0m" << std::endl;
}

WrongCat::~WrongCat()
{
	delete this->brain;
	std::cout << "\x1B[34mWrongCat Destructor called\033[0m" << std::endl;
}

void	WrongCat::setIdeas(std::string ideas, int i)
{
		this->brain->setIdeas(ideas, i);
}

std::string	WrongCat::getIdeas(int i) const
{
	return (this->brain->getIdeas(i));
}


WrongCat &WrongCat::operator=(const WrongCat& other)
{
	this->type = other.type;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "\x1B[34mI'm a cat !\033[0m" << std::endl;
}
