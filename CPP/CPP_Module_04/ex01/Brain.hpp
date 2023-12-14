/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:04:09 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/14 13:07:23 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{

public:
	
	Brain();
	Brain(const Brain &cpy);
	~Brain();

// set //
	void setIdeas(std::string type, int i);

// get //
	std::string getIdeas(int i) const;

// operator //
	Brain	operator=(const Brain &other);


protected:
	std::string	ideas[100];
	
};
# endif

