/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:16:38 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/14 13:46:17 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
	public:
	
	Cat(void);
	Cat(const Cat &cpy);
	~Cat();

// operator //
	Cat	&operator=(const Cat &other);

// functions //
	void makeSound(void) const ;	
};

#endif
