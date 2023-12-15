/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:38:21 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/15 12:37:42 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class WrongAnimal
{

public:
	
	WrongAnimal();
	WrongAnimal(const WrongAnimal &cpy);
	virtual ~WrongAnimal();

// operator //
	WrongAnimal	&operator=(const WrongAnimal &other);

// set //
	void setType(std::string type);

// get //
	std::string getType(void) const;

// functions //
	virtual void makeSound(void) const ;

protected:
	std::string	type;
	
};
# endif
