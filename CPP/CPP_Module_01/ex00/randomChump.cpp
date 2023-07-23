/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:44:56 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/19 14:07:23 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	 randomChump( std::string name )
{
	Zombie	*tmp;

	tmp = newZombie(name);
	tmp->announce();
	delete(tmp);
}

