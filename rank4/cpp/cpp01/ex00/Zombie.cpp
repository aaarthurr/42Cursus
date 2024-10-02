/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:08:24 by arpages           #+#    #+#             */
/*   Updated: 2024/06/14 15:00:30 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << name << " has been summoned from the dead" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " went back to his grave" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name;
    std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}