/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:48:35 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/23 12:43:41 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

	// Constructor Destructor //

Fixed::Fixed()
{
	this->_raw = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &cpy)
{
	this->_raw = cpy._raw;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


	// Functions //

Fixed& Fixed::operator=(const Fixed& other)
{
	this->_raw = other._raw;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

void Fixed::setRawBits( int const raw )
{
	this->_raw = raw;
}
