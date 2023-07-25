/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:48:35 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/25 14:20:06 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

	// Constructor Destructor //

Fixed::Fixed()
{
	this->_raw = 0;
}

Fixed::Fixed(const Fixed &cpy)
{
	*this = cpy;
}

Fixed::Fixed(const int nb)
{
	this->_raw = nb << this->_bits;
}

Fixed::Fixed(const float nb)
{
	_raw = roundf(nb * (1 << _bits));
}

Fixed::~Fixed()
{
}


	// Check Operator //

bool Fixed::operator>(const Fixed& other)
{
	if (this->_raw > other._raw)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& other)
{
	if (this->_raw < other._raw)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& other)
{
	if (this->_raw >= other._raw)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& other)
{
	if (this->_raw <= other._raw)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& other)
{
	if (this->_raw = other._raw)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& other)
{
	if (this->_raw = other._raw)
		return (false);
	return (true);
}


	// asignement operator //

Fixed& Fixed::operator=(const Fixed& other)
{
	this->_raw = other._raw;
	return (*this);
}

Fixed& Fixed::operator+(const Fixed& other)
{
	this->_raw += other._raw;
	return (*this);
}

Fixed& Fixed::operator-(const Fixed& other)
{
	this->_raw -= other._raw;
	return (*this);
}

Fixed& Fixed::operator*(const Fixed& other)
{
	this->_raw *= other._raw >> _bits;
	return (*this);
}

Fixed& Fixed::operator/(const Fixed& other)
{
	this->_raw /= other._raw >> _bits;
	return (*this);
}


	// incrementstion operator //

Fixed& Fixed::operator++()
{
	this->_raw++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->_raw++;
	return (tmp);
}

Fixed& Fixed::operator--()
{
	this->_raw--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->_raw--;
	return (tmp);
}


	// check function //


	// Functions //

int Fixed::getRawBits( void ) const
{
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
