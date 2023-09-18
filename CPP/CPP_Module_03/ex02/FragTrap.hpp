/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:44:16 by tdutel            #+#    #+#             */
/*   Updated: 2023/09/18 11:59:37 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"
# include <iostream>

class FragTrap : public ClapTrap
{

public:
//constructor destructor //
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const	FragTrap &scavTrap);
	~FragTrap();

// operator //
	FragTrap	&operator=(const FragTrap &scavTrap);
// functions //
	void guardGate();
	void attack(const std::string& target);
	void highFivesGuys(void);
};

#endif
