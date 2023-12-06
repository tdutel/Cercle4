/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:36:19 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/06 14:47:15 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int	main(void)
{
	ClapTrap cp1("Charizard");
	ClapTrap cp2("Blastoise");
	ClapTrap cp3("Venusaur");
	std::cout << std::endl;

//init stats
	cp1.setStats(9, 2, 8);
	cp2.setStats(5, 5, 10);
	cp3.setStats(4, 10, 5);

	cp3.attack("Blastoise");
	cp2.takeDamage(cp3.getAttackDamage());
	cp2.beRepaired(2);
	cp2.beRepaired(2);
	cp2.attack("Charizard");
	cp1.takeDamage(cp2.getAttackDamage());
	cp1.attack("Venusaur");
	cp3.takeDamage(cp1.getAttackDamage());
	cp3.attack("Charizard and Blastoise");
	cp2.setAttackDamage(10);
	std::cout << cp2.getName() << " focuses..." << std::endl;
	cp2.attack("Charizard");
	cp1.takeDamage(cp2.getAttackDamage());
	cp1.beRepaired(10);
	std::cout << cp2.getName() << " is the winner !" << std::endl << std::endl;
	return (0);
}
