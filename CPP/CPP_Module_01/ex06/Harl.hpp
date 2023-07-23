/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:40:39 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/21 13:40:42 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{

public:
	void complain( std::string level );
	Harl();
	~Harl();

private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};

#endif
