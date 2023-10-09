/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:48:52 by tdutel            #+#    #+#             */
/*   Updated: 2023/10/09 14:28:13 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

	// Constructor Destructor //

Animal::Animal(void)
{
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}


void	Animal::setType(std::string type)
{
	this->type = type;
}

std::string	Animal::getType(void)
{
	return (this->type);
}

void Animal::makeSound(void)
{
	if (this->type == "Dog")
		std::cout << "Bark !" << std::endl;
	else if (this->type == "Cat")
		std::cout << "Meow !" << std::endl;
	else
		std::cout << "*unknown cry*" << std::endl;
}
