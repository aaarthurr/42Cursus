/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:04:22 by arpages           #+#    #+#             */
/*   Updated: 2024/06/15 13:39:33 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <iomanip>
#include <limits>

#include "Weapon.hpp"

class HumanB
{
private:
    Weapon      *_weapon;
    std::string _name;
public:
    HumanB(std::string name);
    ~HumanB();
    void attack(void);
    void setWeapon(Weapon &Weapon);
};

#endif