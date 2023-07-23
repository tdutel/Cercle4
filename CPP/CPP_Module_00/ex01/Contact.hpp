/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:44:12 by tdutel            #+#    #+#             */
/*   Updated: 2023/04/20 11:03:35 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {
	
public:

	Contact();
	~Contact();

	void		setFirstName(std::string firstName);
	std::string	getFirstName() const;
	
	void		setLastName(std::string lastName);
	std::string	getLastName() const;

	void		setNickname(std::string nickname);
	std::string	getNickname() const;

	void		setPhoneNumber(std::string phoneNumber);
	std::string	getPhoneNumber() const;
	
	void		setDarkestSecret(std::string darkestSecret);
	std::string	getDarkestSecret() const;


private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

};

#endif
