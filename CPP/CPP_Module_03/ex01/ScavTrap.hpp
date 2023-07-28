/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:16:19 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/28 12:53:02 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap
{

public:
//constructor destructor //
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const	ScavTrap &scavTrap);
	~ScavTrap();

// operator //
	ScavTrap	&operator=(const ScavTrap &scavTrap);
// functions //
	void guardGate();
	void attack(const std::string& target);
};


#endif
