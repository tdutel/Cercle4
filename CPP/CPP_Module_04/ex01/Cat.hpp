/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:16:38 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/14 13:57:10 by tdutel           ###   ########.fr       */
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

// set //
	void setIdeas(std::string type, int i);

// get //
	std::string getIdeas(int i) const;

// operator //
	Cat	&operator=(const Cat &other);

// functions //

	void makeSound(void) const ;

	private:
	Brain *brain;
};

#endif
