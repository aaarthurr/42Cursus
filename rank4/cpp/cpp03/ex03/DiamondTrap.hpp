/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:34:51 by arthur            #+#    #+#             */
/*   Updated: 2024/06/23 21:16:35 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define	DIAMONDTRAP_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string _name;

public:
    DiamondTrap(std::string name);
    ~DiamondTrap();

    using ScavTrap::attack;

    void whoAmI(void);
};
#endif