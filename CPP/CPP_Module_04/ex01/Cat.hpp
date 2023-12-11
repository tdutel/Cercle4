/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:16:38 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/11 15:24:07 by tdutel           ###   ########.fr       */
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

	private:
	Brain *brain;
};

#endif
