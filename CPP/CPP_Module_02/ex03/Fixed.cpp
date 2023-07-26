/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:48:35 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/26 13:54:52 by tdutel           ###   ########.fr       */
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
	_raw = (int)roundf(nb * (1 << _bits));
}

Fixed::~Fixed()
{
}


	// Check Operator //

bool Fixed::operator>(const Fixed& other) const
{
	if (this->_raw > other._raw)
		return (true);
	return (false);
	// return (this->_raw > other._raw);
}

bool Fixed::operator<(const Fixed& other) const
{
	if (this->_raw < other._raw)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& other) const
{
	if (this->_raw >= other._raw)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& other) const
{
	if (this->_raw <= other._raw)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& other) const
{
	// if (this->_raw = other._raw)
	// 	return (true);
	// return (false);
	return (this->_raw == other._raw);
}

bool Fixed::operator!=(const Fixed& other) const
{
	// if (this->_raw = other._raw)
	// 	return (false);
	// return (true);
	return (this->_raw != other._raw);
}


	// asignement operator //

Fixed& Fixed::operator=(const Fixed& other)
{
	this->_raw = other.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	// this->_raw += other._raw >> _bits;
	// return (*this);
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
	// this->_raw -= other._raw >> _bits;
	// return (*this);
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
	// this->_raw *= other._raw >> _bits;
	// return (*this);
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
	// if (other._raw >> _bits == 0)
	// 	{std::cout << "Error division by 0\n";
	// 	exit;}
	// this->_raw /= other._raw >> _bits;
	// return (*this);
	if (other.toFloat() == 0)
    {
        std::cerr << "Error: Division by zero!" << std::endl;
        return Fixed();
    }
    return Fixed(this->toFloat() / other.toFloat());
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

static Fixed& min(Fixed &f1, Fixed &f2)
{
	if ( f1 <= f2)
		return (f1);
	return (f2);
}
static const Fixed& min(const Fixed &f1, const Fixed &f2)
{
	if ( (Fixed)f1 <= (Fixed)f2)
		return (f1);
	return (f2);
}
static Fixed& max(Fixed &f1, Fixed &f2){
	if ( f1 >= f2)
		return (f1);
	return (f2);
}
static const Fixed& max(const Fixed &f1, const Fixed &f2)
{
	if ( (Fixed)f1 >= (Fixed)f2)
		return (f1);
	return (f2);
}

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
	// return (_raw >> _bits) ;
	return ((int)(roundf((float)_raw / (1 << _bits))));
}

std::ostream& operator<<(std::ostream &out, const Fixed& other)
{
	out << other.toFloat();
	return (out);
}
