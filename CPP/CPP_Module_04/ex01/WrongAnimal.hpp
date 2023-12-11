/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:38:21 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/11 13:46:37 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{

public:
	
	WrongAnimal();
	WrongAnimal(const WrongAnimal &cpy);
	~WrongAnimal();

// operator //
	WrongAnimal	&operator=(const WrongAnimal &other);

// set //
	void setType(std::string type);

// get //
	std::string getType(void) const;

// functions //
	void makeSound(void) const ;

protected:
	std::string	type;
	
};
# endif
