/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:49:26 by tdutel            #+#    #+#             */
/*   Updated: 2023/12/12 13:46:00 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


//TODO: Enlever appel a std::copy, 
//se renseigner sur deep/shallow copy, polymorphism et le keyword virtual 
int main()
{
// const	Dog i;
const Animal* j = new Dog();
const Animal* i = new Cat();

// Animal *array[50];
// array[0] = new Dog();

delete j;//should not create a leak
delete i;
return (0);
}
