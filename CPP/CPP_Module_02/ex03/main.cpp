/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:40:18 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/25 15:57:47 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main( void ) {
Point	A(0,0);
Point	B(3,2);
Point	C(5,0);

float	x;
float	y;

std::cout << "enter x :" << std::endl;
std::cin >> x;
std::cout << "enter y :" << std::endl;
std::cin >> y;

Point	U(x, y);
if (bsp(A, B, C, U) == true)
	std::cout << "point U is in ABC triangle :D" << std::endl;
else
	std::cout << "point U is not in ABC triangle :O" << std::endl;
return 0;
}
