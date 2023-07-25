/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:42:22 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/25 15:13:07 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


	// Constructo Destructor //

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &cpy)
{
	*this = cpy;
}

Point::~Point()
{
}

	// operator //

Point& Point::operator=(const Point& other)
{
	Fixed(this->_x) = Fixed(other._x);
	Fixed(this->_y) = Fixed(other._y);
	return (*this);
}

	// function //

Fixed	Point::getx(void) const
{
	return (this->_x);
}

Fixed	Point::gety(void) const
{
	return (this->_y);
}
