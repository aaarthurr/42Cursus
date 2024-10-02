/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:42:07 by arthur            #+#    #+#             */
/*   Updated: 2024/06/23 21:21:44 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap( name ), FragTrap( name ), ScavTrap( name )
{
    this->_name = name;
    this->ClapTrap::_name = name + "\033[1;35m_clap_name\033[0m";
	
    FragTrap::_hitPoints = 100;
    ScavTrap::_energyPoints = 50;
    FragTrap::_attackDamage = 30;
    
    std::cout << "DiamondTrap : " << name << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "ClapTrap Basic destuctor called : " << this->_name << std::endl;
}

void    DiamondTrap::whoAmI( void ) {
    std::cout << "I am a DiamondTrap named " << this->_name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
