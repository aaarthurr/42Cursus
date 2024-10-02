/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:53:30 by arthur            #+#    #+#             */
/*   Updated: 2024/06/24 18:07:12 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << this->_type << " constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << this->_type << " destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "**Meoooooooooow**" << std::endl;
}