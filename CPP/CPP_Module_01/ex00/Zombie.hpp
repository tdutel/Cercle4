/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:57:37 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/19 14:07:15 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {

public:
	
	void	announce( void );

	Zombie(std::string name);
	~Zombie();

private:

	std::string	name;

};

Zombie* newZombie( std::string name );
void	 randomChump( std::string name );

#endif

