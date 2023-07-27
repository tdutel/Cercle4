/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:30:53 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/27 15:37:30 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// bool	bsp(const Point a, const Point b, const Point c, const Point point)
// {
// 	// float	s1, s2, s3;

// 	// s1 = Point::signThree(point, a, b);
// 	// s2 = Point::signThree(point, b, c);
// 	// s3 = Point::signThree(point, c, a);
// 	// return ((s1 < 0 && s2 < 0 && s3 < 0) || (s1 > 0 && s2 > 0 && s3 > 0));
// 	std::cout << "A : x=" << a.getX() << " y=" << a.getY() << std::endl;
// 	std::cout << "B : x=" << b.getX() << " y=" << b.getY() << std::endl;
// 	std::cout << "C : x=" << c.getX() << " y=" << c.getY() << std::endl;
// 	std::cout << "U : x=" << point.getX() << " y=" << point.getY() << std::endl;
// 	return true;	
// }

bool bsp( Point const &a, Point const &b, Point const &c, Point const &point)
{
	std::cout << "A : x=" << a.getX() << " y=" << a.getY() << std::endl;
	std::cout << "B : x=" << b.getX() << " y=" << b.getY() << std::endl;
	std::cout << "C : x=" << c.getX() << " y=" << c.getY() << std::endl;
	// std::cout << b.getY() << c.getY() << point.getX() << c.getX() << c.getX() << b.getX() << point.getY() << c.getY() <<
	// b.getY() << c.getY() << a.getX() << c.getX() << c.getX() << b.getX() << a.getY() << c.getY();
	float alpha = ((b.getY() - c.getY()) * (point.getX() - c.getX()) + (c.getX() - b.getX()) * (point.getY() - c.getY())) /
	((b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY()));
	// std::cout << alpha << std::endl;
	float beta  = ((c.getY() - a.getY()) * (point.getX() - c.getX()) + (a.getX() - c.getX()) * (point.getY() - c.getY())) /
	((b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY()));
	// std::cout << beta << std::endl;

	float gamma = 1 - alpha - beta;
	return (alpha > 0 && alpha < 1 && beta > 0 && beta < 1 && gamma > 0 && gamma < 1);
}
