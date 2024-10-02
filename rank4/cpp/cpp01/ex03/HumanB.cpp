/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:10:36 by arpages           #+#    #+#             */
/*   Updated: 2024/06/15 13:47:11 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
    this->_weapon = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::attack(void)
{
    if (this->_weapon == NULL || this->_weapon->getType() == "")
        std::cout << this->_name << " attacks with his hands" << std::endl;
    else
    {
        std::cout << this->_name ;
        std::cout << " attacks with their " ;
        std::cout << this->_weapon->getType() << std::endl;
    }
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}