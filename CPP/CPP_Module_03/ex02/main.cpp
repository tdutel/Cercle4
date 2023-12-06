/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:36:19 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/06 15:15:43 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main()
{
	ClapTrap	cp1("Charizard");
	FragTrap	fp1("ARCEUS");

	std::cout << std::endl;
	cp1.setAttackDamage(5);
	cp1.attack(fp1.getName());
	fp1.takeDamage(cp1.getAttackDamage());
	fp1.guardGate();
	fp1.beRepaired(5);
	std::cout << std::endl;
	fp1.attack(cp1.getName());
	cp1.takeDamage(fp1.getAttackDamage());
	std::cout << std::endl;

	cp1.attack(fp1.getName());
	fp1.attack(cp1.getName());
	cp1.takeDamage(fp1.getAttackDamage());
	cp1.attack(fp1.getName());
	std::cout << fp1.getName() << " won the game !" << std::endl << std::endl;
	fp1.highFivesGuys();
	return (0);
}
