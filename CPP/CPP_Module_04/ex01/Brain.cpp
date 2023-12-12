/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:10:24 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/12 13:56:20 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

	// Constructor Destructor //

Brain::Brain(void)
{
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::Brain(const Brain &cpy)
{
	//verifier que this est cpy ne sont pas egaux.
	// if (*this != cpy)
		*this = cpy;
	//TODO std::copy is member of algorithms, forbidden here
	std::copy(begin(cpy.ideas), end(cpy.ideas), this->ideas);
	std::cout << "Copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain Brain::operator=(const Brain& other)
{
	//TODO std::copy is member of algorithms, forbidden here
	for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}
