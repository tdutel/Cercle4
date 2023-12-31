/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:49:26 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/15 13:05:30 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    
std::cout << std::endl << "\x1b[35mCREATING AN ARRAY OF 10 ANIMALS (5 DOGS AND 5 CATS) :\033[0m" << std::endl << std::endl;


Animal *array[10];

for (size_t i = 0; i < 5; i++){
    std::cout << "\x1B[31m  Dog\033[0m \x1b[33m[" << i <<"]\033[0m" << std::endl;
	array[i] = new Dog();
    std::cout << std::endl;
}
for (size_t i = 5; i < 10; i++){
    std::cout << "\x1B[34m  Cat\033[0m \x1b[33m[" << i <<"]\033[0m" << std::endl;
	array[i] = new Cat();
    std::cout << std::endl;
}


std::cout << "\x1b[35mTESTING makeSound FUNCTION FOR EACH ANIMALS :\033[0m" << std::endl << std::endl;


for (size_t i = 0; i < 10; i++){
	std::cout << "\x1b[32mAnimal\033[0m \x1b[33m[" << i << "]\033[0m: " << array[i]->getType() << ": ";
	array[i]->makeSound();
}


std::cout << std::endl << "\x1b[35mDELETING ALL ANIMALS :\033[0m" << std::endl << std::endl;


for (size_t i = 0; i < 10; i++){
    std::cout << "\x1B[32m  Animal\033[0m \x1b[33m[" << i <<"]\033[0m" << std::endl;
	delete array[i];
    std::cout << std::endl;
}


std::cout << std::endl << "\x1b[35mTESTING ideas :\033[0m" << std::endl << std::endl;


Cat kitty;
kitty.setIdeas("taking a nap", 0);
std::cout << "Kitty think about " << "\x1b[34m" << kitty.getIdeas(0) << " !\033[0m" << std::endl;
std::cout << std::endl;


std::cout << std::endl << "\x1b[35mTESTING WRONGCAT (makeSound and ideas) :\033[0m" << std::endl << std::endl;


WrongCat wrongkitty;
std::cout << "WrongKitty : ";
wrongkitty.makeSound();
wrongkitty.setIdeas("playing Fortnite", 0);
std::cout << "WrongKitty think about " << "\x1b[34m" << wrongkitty.getIdeas(0) << " !\033[0m" << std::endl;
std::cout << std::endl;


std::cout << std::endl << "\x1b[35mTESTING COPY :\033[0m" << std::endl << std::endl;


Dog doggy;
doggy.setIdeas("eating", 0);
std::cout << "Doggy think about " << "\x1b[31m" << doggy.getIdeas(0) << " !\033[0m" << std::endl;
std::cout << std::endl;

Dog copydoggy(doggy);
std::cout << "CopyDoggy think about " << "\x1b[31m" << doggy.getIdeas(0) << " !\033[0m" << std::endl;
std::cout << std::endl;


std::cout << std::endl << "\x1b[35mDESTRUCTOR :\033[0m" << std::endl << std::endl;

return (0);
}
