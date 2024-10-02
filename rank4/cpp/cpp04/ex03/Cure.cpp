/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:14:07 by arthur            #+#    #+#             */
/*   Updated: 2024/06/25 15:28:04 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(/* args */) : AMateria("cure")
{
}

Cure::Cure(Cure const & src) : AMateria("cure")
{
	*this = src;
}

Cure& Cure::operator=(const Cure& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return(*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

Cure::~Cure()
{
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; 
}