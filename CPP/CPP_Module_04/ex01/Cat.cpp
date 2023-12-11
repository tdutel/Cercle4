/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:17:38 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/11 15:36:43 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

	// Constructor Destructor //

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	this->type = "Cat";
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat()
{
	// delete[] this->brain;
	std::cout << "Cat Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other)
{
	this->type = other.type;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}
