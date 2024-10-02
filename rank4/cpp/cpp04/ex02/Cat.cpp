/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:53:30 by arthur            #+#    #+#             */
/*   Updated: 2024/06/24 19:31:17 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << this->_type << " constructor called" << std::endl;
	try {
		this->_brain = new Brain();
	}
	catch (const std::bad_alloc& e) {
		std::cout << "Allocation error : " << e.what() << std::endl;
	}
}

Cat::~Cat()
{
	std::cout << this->_type << " destructor called" << std::endl;
	delete this->_brain;
}

Cat::Cat(const Cat& src) : Animal(src)
{
	*this = src;
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout << "Cat copy called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = new Brain(*src._brain);
	}
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "**Meoooooooooow**" << std::endl;
}