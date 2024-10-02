/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:14:09 by arthur            #+#    #+#             */
/*   Updated: 2024/06/25 15:28:18 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(/* args */) : AMateria("ice")
{
}

Ice::Ice(Ice const & src) : AMateria("ice")
{
	*this = src;
}

Ice& Ice::operator=(const Ice& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return(*this);
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

Ice::~Ice()
{
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; 
}