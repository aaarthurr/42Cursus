/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:56:24 by arpages           #+#    #+#             */
/*   Updated: 2024/06/24 19:36:30 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << this->_type << " constuctor called" << std::endl;
	try {
		this->_brain = new Brain();
	}
	catch (const std::bad_alloc& e) {
		std::cout << "Allocation error : " << e.what() << std::endl;
	}
}

Dog::~Dog()
{
	std::cout << this->_type << " destructor called" << std::endl;
	delete this->_brain;
}

Dog::Dog(const Dog& src) : Animal(src)
{
	*this = src;
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout << "Dog copy called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = new Brain(*src._brain);
	}
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "**WOOF WOOF WOOF**" << std::endl;
}