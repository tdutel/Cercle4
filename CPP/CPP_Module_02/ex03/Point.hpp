/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:39:12 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/25 15:32:29 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
public:

//constructor destructo //
	Point();
	Point(const Point &cpy);
	Point(const float x, const float y);
	~Point();

// operator //
	Point& operator=(const Point& other);

// function //
	Fixed getx(void) const;
	Fixed gety(void) const;

private:
	const Fixed _x;
	const Fixed _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
