/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:14:47 by arpages           #+#    #+#             */
/*   Updated: 2024/06/14 16:36:46 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    //une horde de 10 zombies
    Zombie *horde1 = zombieHorde(10, "Dave");
    for (int i = 0; i < 10; i++)
    {
        horde1[i].announce();
    }
    //une horde vide
    Zombie *horde2 = zombieHorde(0, "jasin");
    //une horde 1...
    horde2 = zombieHorde(1, "Summer");
    horde2[0].announce();
    delete [] horde1;
    delete [] horde2;
}