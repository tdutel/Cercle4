/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:16:38 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/11 13:29:11 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
	
	WrongCat(void);
	WrongCat(const WrongCat &cpy);
	~WrongCat();

// set //
	void setIdeas(std::string type, int i);

// get //
	std::string getIdeas(int i) const;

// operator //
	WrongCat	&operator=(const WrongCat &other);

// functions //

	void makeSound(void) const ;

	private:
	Brain *brain;
};

#endif
