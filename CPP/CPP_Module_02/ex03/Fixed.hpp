/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:46:45 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/26 13:54:50 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed {

public:

// constructor destructor /
	Fixed();
	Fixed(const Fixed &cpy);
	Fixed(const int nb);
	Fixed(const float nb);
	~Fixed();

// check operator //
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

// assignment operator //
	Fixed& operator=(const Fixed& other);
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

// incrementation operator //
	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);

// check function //
	static Fixed& min(Fixed &f1, Fixed &f2);
	static Fixed& max(Fixed &f1, Fixed &f2);
	static const Fixed& min(const Fixed &f1, const Fixed &f2);
	static const Fixed& max(const Fixed &f1, const Fixed &f2);

// old function //
	int getRawBits( void ) const;
	void setRawBits( const int raw );
	
	float toFloat( void ) const;
	int toInt( void ) const;


private:
	int _raw;
	static const int _bits = 8;
};
std::ostream& operator<<(std::ostream &out, const Fixed& other);
#endif
