/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:49:12 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/15 13:18:36 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{

public:
	
	Animal();
	Animal(const Animal &cpy);
	virtual ~Animal();

// operator //
	Animal	&operator=(const Animal &other);

// set //
	void setType(std::string type);

// get //
	std::string getType(void) const;

// functions //
	virtual void makeSound(void) const = 0;

protected:
	std::string	type;
	
};
# endif
