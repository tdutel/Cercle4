/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:29:32 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/26 14:27:32 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main( void ) {
Point	a(0, 0);
Point	b(3, 2);
Point	c(5, 0);

// float	x;
// float	y;

// std::cout << "A : x=" << a.getX() << " y=" << a.getY() << std::endl;
// std::cout << "B : x=" << b.getX() << " y=" << b.getY() << std::endl;
// std::cout << "C : x=" << c.getX() << " y=" << c.getY() << std::endl;

// std::cout << "enter x :" << std::endl;
// std::cin >> x;
// std::cout << "enter y :" << std::endl;
// std::cin >> y;

Point	point(1, 2);
// std::cout << "U : x=" << point.getX() << " y=" << point.getY() << std::endl;

bsp(a, b, c, point);
return (0);
}
