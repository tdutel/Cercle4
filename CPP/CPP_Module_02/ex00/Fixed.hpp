/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:48:25 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/23 12:46:30 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {

public:

	Fixed& operator=(const Fixed& other);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	Fixed();
	Fixed(const Fixed &cpy);
	~Fixed();

private:
	int _raw;
	const static int _bits = 8;
};

#endif
