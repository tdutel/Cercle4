/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:24:08 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/20 12:14:56 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {

public:
	
	void	attack( void );

	HumanA(std::string name, Weapon	&Weapon);
	~HumanA();

private:

	Weapon	&_Weapon;
	std::string _name;

};

#endif
