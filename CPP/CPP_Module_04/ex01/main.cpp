/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:49:26 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/13 13:43:07 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

//se renseigner sur deep/shallow copy, polymorphism et le keyword virtual 
int main()
{

Animal *array[20];

for (size_t i = 0; i < 10; i++)
{
	array[i] = new Dog();
}
for (size_t i = 10; i < 20; i++)
{
	array[i] = new Cat();
}

for (size_t i = 0; i < 20; i++)
{
	std::cout << "Animal[" << i << "]: " << array[i]->getType() << ": ";
	array[i]->makeSound();
}


for (size_t i = 0; i < 20; i++)
{
	delete array[i];
}

return (0);
}
