/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:35:43 by arthur            #+#    #+#             */
/*   Updated: 2024/06/25 15:26:48 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Character named : " << name << " created" << std::endl;
}

Character::Character(Character const & src) : _name(src._name)
{
	*this = src;
	std::cout << "Character named : " << this->_name << " duplicated" << std::endl;
}

Character& Character::operator=(Character const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = rhs._inventory[i];
	}
	return *this;
}

Character::~Character()
{
    std::cout << "Character named : " << this->_name << " destroyed" << std::endl;
    for (int i = 0; i < 4; i++)
        if (this->_inventory[i])
            delete this->_inventory[i];
}

void    Character::equip( AMateria* m )
{
    for (int i = 0; i < 4; i++)
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            std::cout << "Character : " << this->_name << " has equipped " << m->getType() << std::endl;
            return;
        }
    std::cout << "Character " << this->_name << " inventory is full : can't equip " << m->getType() << std::endl;
}

void    Character::unequip( int idx )
{
    if (this->_inventory[idx])
    {
        delete this->_inventory[idx];
        this->_inventory[idx] = NULL;
        std::cout << "Character " << this->_name << " has unequipped" << std::endl;
    }
    else
        std::cout << "Character " << this->_name << " has no weapon at this slot" << std::endl;
}

void    Character::use( int idx, ICharacter& target )
{
    if (this->_inventory[idx])
    {
        this->_inventory[idx]->use(target);
        std::cout << "Character " << this->_name << " uses " << this->_inventory[idx]->getType() << std::endl;
    }
    else
        std::cout << "Character " << this->_name << " has no weapon at this slot" << std::endl;
}

std::string const& Character::getName() const
{
    return this->_name;
}