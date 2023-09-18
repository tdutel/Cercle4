/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:35:53 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/28 12:41:14 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &clapTrap);
	~ClapTrap();

// set //
	void setHitPoints(int n);
	void setEnergyPoints(int n);
	void setAttackDamage(int n);
	void setStats( int attack, int energy, int hp);

	std::string getName(void);
	int getAttackDamage(void);
	int getEnergyPoints(void);
	int getHitPoints(void);


// functions //
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);


	ClapTrap	&operator=(const ClapTrap &clapTrap);

protected:
	std::string	_name;
	int	_hitPoints = 10;
	int _energyPoints = 10;
	int	_attackDamage = 0;
	
};

#endif
