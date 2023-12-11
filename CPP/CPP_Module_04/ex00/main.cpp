/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:49:26 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/11 14:03:07 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout << std::endl << j->getType() << ": ";
j->makeSound();
std::cout << std::endl << i->getType() << ": ";
i->makeSound();
std::cout << std::endl << "none of them : ";
meta->makeSound();
std::cout << std::endl;

const WrongAnimal* x = new WrongCat();

std::cout << std::endl << x->getType() << ": ";
x->makeSound();
std::cout << std::endl;

delete(meta);
delete(j);
delete(i);
delete(x);

return 0;
}
