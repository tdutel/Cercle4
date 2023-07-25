/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:39:12 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/25 14:50:52 by tdutel           ###   ########.fr       */
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

private:
	const Fixed _x;
	const Fixed _y;
};
