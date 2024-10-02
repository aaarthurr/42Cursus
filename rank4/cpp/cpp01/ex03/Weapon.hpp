/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:41:54 by arpages           #+#    #+#             */
/*   Updated: 2024/06/15 13:43:41 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <iomanip>
#include <limits>

class Weapon
{
private:
    std::string _type;
public:
    Weapon(std::string type);
    ~Weapon();
    const std::string &getType(void);
    void setType(std::string type);
};

#endif