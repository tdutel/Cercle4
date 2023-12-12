/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:04:09 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/12 13:49:16 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <algorithm>

class Brain
{

public:
	
	Brain();
	Brain(const Brain &cpy);
	~Brain();

// operator //
	Brain	operator=(const Brain &other);


protected:
	std::string	ideas[100];
	
};
# endif

