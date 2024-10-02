/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:48:22 by arthur            #+#    #+#             */
/*   Updated: 2024/06/24 14:14:04 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;

	std::cout << "ScavTrap : " << name << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Basic destructor called : " << this->_name << std::endl;
}

void    ScavTrap::attack( std::string const& target )
{
    if ( this->_energyPoints <= 0 ) {
        std::cout << "ScavTrap " << this->_name << " is out of energy." << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", dealing " << this->_attackDamage << " damage !" << std::endl;
    this->_energyPoints -= 1;
}

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}