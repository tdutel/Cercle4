/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:51:11 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/14 13:47:10 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
	
	Dog(void);
	Dog(const Dog &cpy);
	~Dog();

// operator //
	Dog	&operator=(const Dog &other);

// functions //
	void makeSound(void) const ;
	
};

#endif
