/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:25:19 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/19 17:57:18 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int N = 3;
	Zombie	*zombies = zombieHorde(N, "someone");
	for (int i = 0; i < N; i++)
	{
		zombies->announce();
	}
	delete[] zombies;
	return (0);
}
