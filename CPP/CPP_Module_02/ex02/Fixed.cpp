/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:48:35 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/24 12:40:11 by tdutel           ###   ########.fr       */
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
	*this = cpy;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw = nb << this->_bits;
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << this->_raw << std::endl;
	_raw = roundf(nb * (1 << _bits));
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

void Fixed::setRawBits( const int raw )
{
	this->_raw = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)(_raw) / (1 << _bits));
}

int Fixed::toInt(void) const
{
	return (_raw >> _bits) ;
}

std::ostream& operator<<(std::ostream &out, const Fixed& other)
{
	out << other.toFloat();
	return (out);
}
