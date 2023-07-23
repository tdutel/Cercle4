/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:07:42 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/20 17:11:58 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static void	replace_str(std::string &str, std::string argv1, std::string argv2)
{
	size_t npos = 0;
	while(1)
	{
		npos = str.find(argv1, npos);
		if (npos == std::string::npos)
            return;
		str.erase(npos, argv1.length());
		str.insert(npos, argv2);
		npos += argv2.length();
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4 || argv[1][0] == '\0' || argv[2][0] == '\0')
		return (std::cout << "please enter 3 arguments after the executable" << std::endl, 1);
	
	std::ifstream infile;
	std::ofstream outfile;
	std::string	str;

	infile.open(std::string(argv[1]));
	if (!infile.is_open())
		return (std::cout << "unknown file : " << argv[1] << std::endl, 1);
	std::getline(infile, str, '\0');
	infile.close();
	replace_str(str, std::string(argv[2]), std::string(argv[3]));
	
	std::string namefile = std::string(argv[1]);
	namefile.append(".replace");
	outfile.open(namefile);
	outfile << str;
	outfile.close();
	return (0);
}
