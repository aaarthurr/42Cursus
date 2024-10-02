/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:04:22 by arpages           #+#    #+#             */
/*   Updated: 2024/06/15 13:45:53 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <iomanip>
#include <limits>

#include "Weapon.hpp"

class HumanA
{
private:
    std::string _name;
    Weapon      &_weapon;
public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
    void attack(void);
    void setWeapon(Weapon &weapon);
};

#endif