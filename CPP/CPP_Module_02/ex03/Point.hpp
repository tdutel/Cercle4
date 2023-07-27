/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:39:12 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/27 15:38:24 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
public:

//constructor destructor //
	Point();
	Point(const float &x, const float &y);
	Point(const Point &cpy);
	~Point();

// operator //
	Point&	operator=(const Point& other);

// function //
	float getX(void) const;
	float getY(void) const;

private:
	const Fixed	_x;
	const Fixed	_y;
};
bool bsp( Point const &a, Point const &b, Point const &c, Point const &point);

#endif
