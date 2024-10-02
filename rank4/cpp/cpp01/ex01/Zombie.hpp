/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:09:20 by arpages           #+#    #+#             */
/*   Updated: 2024/06/14 15:37:36 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <iomanip>
#include <limits>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie();
        ~Zombie();

        void setName(std::string);
        void announce(void);
};

Zombie*  zombieHorde ( int N, std::string name);

#endif // PHONEBOOK_HPP