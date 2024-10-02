/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:16:05 by arpages           #+#    #+#             */
/*   Updated: 2024/06/14 15:40:31 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*  zombieHorde ( int N, std::string name)
{
    if (N <= 0)
    {
        std::cout << "No Zombie, No problem" << std::endl;
        return (NULL);
    }
    Zombie *horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
        std::cout << name << " joined the horde" << std::endl;
    }
    return (horde);
}
