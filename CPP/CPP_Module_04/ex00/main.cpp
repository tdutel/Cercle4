/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:49:26 by tdutel            #+#    #+#             */
/*   Updated: 2023/10/09 14:22:09 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
// const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
// std::cout << i->getType() << " " << std::endl;
// i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
return 0;
}
