/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:06:41 by tdutel            #+#    #+#             */
/*   Updated: 2023/04/20 16:11:54 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

class PhoneBook {

public:
	
	PhoneBook();
	~PhoneBook();

	int			checkAttribut(std::string atttribut);
	void		setUser(int	i);
	void 		getUser(void);
	std::string	displayAttribut(std::string attribut);
	void		displayDetails(Contact _userList);
	std::string	checkEmpty(Contact user, std::string attribut);

private:

	Contact		_userList[8];

};

#endif
