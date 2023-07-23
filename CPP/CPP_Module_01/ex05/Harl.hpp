/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:13:31 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/21 12:16:40 by tdutel           ###   ########.fr       */
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
