/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:58:14 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/19 14:27:02 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *ptrZ;

	ptrZ = newZombie("Steve Stack");
	ptrZ->announce();
	delete ptrZ;
	randomChump("Cheep Heap");
	return (0);
}
