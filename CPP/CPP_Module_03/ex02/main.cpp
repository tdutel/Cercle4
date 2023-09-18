/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:36:19 by tdutel            #+#    #+#             */
/*   Updated: 2023/09/18 12:14:24 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


// int	main(void)
// {
// 	ClapTrap cp1("Charizard");
// 	ClapTrap cp2("Blastoise");
// 	ClapTrap cp3("Venusaur");
// 	std::cout << std::endl;
// //init stats
// 	cp1.setStats(9, 2, 8);
// 	cp2.setStats(5, 5, 10);
// 	cp3.setStats(4, 10, 5);
// 	cp3.attack("Blastoise");
// 	cp2.takeDamage(cp3.getAttackDamage());
// 	cp2.beRepaired(2);
// 	cp2.beRepaired(2);
// 	cp2.attack("Charizard");
// 	cp1.takeDamage(cp2.getAttackDamage());
// 	cp1.attack("Venusaur");
// 	cp3.takeDamage(cp1.getAttackDamage());
// 	cp3.attack("Charizard and Blastoise");
// 	cp2.setAttackDamage(10);
// 	std::cout << cp2.getName() << " focuses..." << std::endl;
// 	cp2.attack("Charizard");
// 	cp1.takeDamage(cp2.getAttackDamage());
// 	cp1.beRepaired(10);
// 	std::cout << cp2.getName() << " is the winner !" << std::endl << std::endl;
// 	return (0);
// }

int	main()
{
	ClapTrap	cp1("Pikachu");
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
	std::cout << std::endl << "Morality : this scenario become really weird." << std::endl << std::endl;
	return (0);
}
