/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:36:19 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/06 14:52:35 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	cp1("Charizard");
	ScavTrap	sp1("Mega Rayquaza");

	std::cout << std::endl;
	cp1.setAttackDamage(5);
	cp1.attack(sp1.getName());
	sp1.guardGate();
	sp1.takeDamage(cp1.getAttackDamage());
	sp1.beRepaired(5);
	std::cout << std::endl;
	sp1.attack(cp1.getName());
	cp1.takeDamage(sp1.getAttackDamage());
	std::cout << std::endl;

	cp1.attack(sp1.getName());
	sp1.attack(cp1.getName());
	cp1.takeDamage(sp1.getAttackDamage());
	cp1.attack(sp1.getName());
	std::cout << sp1.getName() << " won the game !" << std::endl << std::endl;
	std::cout << "Morality : a legendary ScavTrap is much better than a simple ClapTrap." << std::endl << std::endl;
	return (0);
}
