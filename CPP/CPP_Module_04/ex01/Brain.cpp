/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:10:24 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/15 11:55:16 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

	// Constructor Destructor //

Brain::Brain(void)
{
	std::cout << "Brain Constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		this->setIdeas("nothing", i);
	}
}

Brain::Brain(const Brain &cpy)
{
	//verifier que this est cpy ne sont pas egaux.
	// if (*this != cpy)
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = cpy.ideas[i];
	}
	std::cout << "Brain Copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}


void	Brain::setIdeas(std::string ideas, int i)
{
		this->ideas[i] = ideas;
}

std::string	Brain::getIdeas(int i) const
{
	return (this->ideas[i]);
}


Brain Brain::operator=(const Brain& other)
{
	for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
	}
	std::cout << "Brain Copy assignment operator called" << std::endl;
	return (*this);
}
