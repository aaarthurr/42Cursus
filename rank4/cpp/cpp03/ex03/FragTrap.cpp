/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:45:50 by arthur            #+#    #+#             */
/*   Updated: 2024/06/23 20:53:20 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;

    std::cout << "FragTrap : " << this->_name << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Basic destructor called " << this->_name  << std::endl;
}

void    FragTrap::highFive( void ) {
    if ( this->_energyPoints <= 0 ) {
        std::cout << "FragTrap " << this->_name << " is out of energy." << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->_name << " high fives everybody." << std::endl;
    this->_energyPoints -= 1;
}