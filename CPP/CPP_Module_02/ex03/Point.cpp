/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:42:22 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/26 14:29:00 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


	// Constructor Destructor //

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float &x, const float &y) : _x(Fixed(x)), _y(Fixed(y))
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

float Point::getX(void) const
{
	return (this->_x.toFloat());
}

float Point::getY(void) const
{
	return (this->_y.toFloat());
}

// float	Point::signThree(const Point &a, const Point &b, const Point &c)
// {
// 	Fixed	fixed;

// 	fixed = (a._x - c._x) * (b._y - c._y) - (b._x - c._x) * (a._y - c._y);
// 	return (fixed.toFloat());
// }

// std::ostream &operator<<(std::ostream &o, const Point &point)
// {
// 	o << "(" << point.getX() << "," << point.getY() << ")";
// 	return (o);
// }
