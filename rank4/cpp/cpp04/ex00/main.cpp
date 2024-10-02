/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:44:52 by arpages           #+#    #+#             */
/*   Updated: 2024/06/24 18:30:54 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "--------" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "--------" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
	
	std::cout << "-- -- --WrongAnimal-- -- --" << std::endl;
	
	const WrongAnimal* wrongA = new WrongAnimal();
	const WrongAnimal* wrongB = new WrongCat();
	std::cout << "--------" << std::endl;
	std::cout << wrongA->getType() << " " << std::endl;
	std::cout << wrongB->getType() << " " << std::endl;
	std::cout << "--------" << std::endl;
	wrongA->makeSound(); 
	wrongB->makeSound();
	delete wrongA;
	delete wrongB;
	return 0;
}