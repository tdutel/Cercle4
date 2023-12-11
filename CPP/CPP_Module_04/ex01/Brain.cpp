/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:10:24 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/11 15:35:41 by tdutel           ###   ########.fr       */
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
	std::copy(begin(cpy.ideas), end(cpy.ideas), this->ideas);
	std::cout << "Copy constructor called" << std::endl;
}

Brain::~Brain()
{
	// delete[] this->ideas;
	std::cout << "Brain Destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	std::copy(begin(other.ideas), end(other.ideas), this->ideas);
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}
