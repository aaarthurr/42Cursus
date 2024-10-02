/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:56:24 by arpages           #+#    #+#             */
/*   Updated: 2024/06/24 18:07:22 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << this->_type << " constuctor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << this->_type << " destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "**WOOF WOOF WOOF**" << std::endl;
}