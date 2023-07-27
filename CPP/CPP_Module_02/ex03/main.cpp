/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:29:32 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/27 13:23:51 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main( void ) {
Point	a(0, 0);
Point	b(3, 2);
Point	c(5, 0);

float	x;
float	y;

std::cout << "A : x=" << a.getX() << " y=" << a.getY() << std::endl;
std::cout << "B : x=" << b.getX() << " y=" << b.getY() << std::endl;
std::cout << "C : x=" << c.getX() << " y=" << c.getY() << std::endl;

std::cout << "enter x :" << std::endl;
std::cin >> x;
std::cout << "enter y :" << std::endl;
std::cin >> y;

Point	point(x, y);
std::cout << "your point : x=" << point.getX() << " y=" << point.getY() << std::endl;


if (bsp(a, b, c, point) == true)
	std::cout << "point U is in ABC triangle :D" << std::endl;
else
	std::cout << "point U is not in ABC triangle :O" << std::endl;
return (0);
}
