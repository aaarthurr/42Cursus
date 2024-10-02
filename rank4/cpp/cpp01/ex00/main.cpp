/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:30:16 by arpages           #+#    #+#             */
/*   Updated: 2024/06/14 14:56:43 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *julius;
    Zombie *kim;
    julius = newZombie("Julius");
    julius->announce();
    kim = newZombie("Kim");
    kim->announce();
    randomChump("Ether");
    delete julius;
    delete kim;
}