/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:48:25 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/24 12:28:59 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed {

public:

	Fixed& operator=(const Fixed& other);
	int getRawBits( void ) const;
	void setRawBits( const int raw );
	
	float toFloat( void ) const;
	int toInt( void ) const;

	Fixed();
	Fixed(const Fixed &cpy);
	Fixed(const int nb);
	Fixed(const float nb);
	~Fixed();

private:
	int _raw;
	static const int _bits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed& other);

#endif
