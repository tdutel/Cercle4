/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:49:12 by tdutel            #+#    #+#             */
/*   Updated: 2023/09/26 14:00:11 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
class Animal
{

public:
	
	Animal();
	~Animal();

// set //
	// void setHitPoints(int n);

// get //
	// int getHitPoints(void);


// functions //
	// void attack(const std::string& target);


	// Animal	&operator=(const Animal &Animal);

private:
	std::string	_name;
	
};
# endif
