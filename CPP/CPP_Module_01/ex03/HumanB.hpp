/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:24:23 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/20 12:25:38 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {

public:
	
	void	attack( void );
	void	setWeapon(Weapon &weapon);
	HumanB(std::string name);
	~HumanB();

private:

	Weapon	*_Weapon;
	std::string _name;

};

#endif
