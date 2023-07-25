/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:54:31 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/25 15:25:59 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed alpha = ((b.gety() - c.gety()) * (point.getx() - c.getx()) + (c.getx() - b.getx()) * (point.gety() - c.gety())) /
	((b.gety() - c.gety()) * (a.getx() - c.getx()) + (c.getx() - b.getx()) * (a.gety() - c.gety()));

	Fixed beta  = ((c.gety() - a.gety()) * (point.getx() - c.getx()) + (a.getx() - c.getx()) * (point.gety() - c.gety())) /
	((b.gety() - c.gety()) * (a.getx() - c.getx()) + (c.getx() - b.getx()) * (a.gety() - c.gety()));

	Fixed gamma = Fixed(1) - alpha - beta;
	return (alpha > 0 && alpha < 1 && beta > 0 && beta < 1 && gamma > 0 && gamma < 1);
}
