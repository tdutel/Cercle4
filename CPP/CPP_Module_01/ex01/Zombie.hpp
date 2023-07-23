/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:26:07 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/19 17:47:02 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {

public:
	
	void	announce( void );
	void	init(std::string name);

	Zombie();
	~Zombie();

private:

	std::string	name;

};

Zombie* zombieHorde( int N, std::string name );

#endif
