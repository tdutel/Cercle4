/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:49:26 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/14 15:28:01 by tdutel           ###   ########.fr       */
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

delete array[0];

std::cout << "Animal[1]: " << array[1]->getType() << ": ";
array[1]->makeSound();

for (size_t i = 1; i < 20; i++)
{
	delete array[i];
}
	
return (0);
}



    // \x1B[31m  \033[0m
    // \x1B[32m  \033[0m
    // \x1B[33m  \033[0m
    // \x1B[34m  \033[0m
    // \x1B[35m  \033[0m
    
    // \x1B[36m  \033[0m
    // \x1B[36m  \033[0m
    // \x1B[36m  \033[0m
    // \x1B[37m  \033[0m
    // \x1B[93m  \033[0m
    
    // \033[3;42;30m  \033[0m
    // \033[3;43;30m  \033[0m
    // \033[3;44;30m  \033[0m
    // \033[3;104;30m  \033[0m
    // \033[3;100;30m  \033[0m

    // \033[3;47;35m  \033[0m
    // \033[2;47;35m  \033[0m
    // \033[1;47;35m  \033[0m
    // printf("\t\t");
    // printf("\n");
