/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:57:35 by arthur            #+#    #+#             */
/*   Updated: 2024/06/23 20:57:18 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

class ClapTrap
{
protected:
    std::string     _name;
    unsigned int    _hitPoints;
    unsigned int    _energyPoints;
    unsigned int    _attackDamage;

public:
    ClapTrap( std::string name );
    ~ClapTrap();

    ClapTrap(const ClapTrap &);
    ClapTrap&       operator=(const ClapTrap& rhs);

    void            attack(std::string const& target);
    void            takeDamage(unsigned int amount);
    void            beRepaired(unsigned int amount);

};

#endif