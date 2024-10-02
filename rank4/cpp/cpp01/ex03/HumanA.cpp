/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:10:36 by arpages           #+#    #+#             */
/*   Updated: 2024/06/15 13:47:18 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack(void)
{
    if (this->_weapon.getType() == "")
        std::cout << this->_name << " attacks with his hands" << std::endl;
    else
    {
        std::cout << this->_name ;
        std::cout << " attacks with their " ;
        std::cout << this->_weapon.getType() << std::endl;
    }
}

void HumanA::setWeapon(Weapon &Weapon)
{
    this->_weapon = Weapon;
}