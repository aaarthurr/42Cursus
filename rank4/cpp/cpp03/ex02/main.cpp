/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:27:40 by arthur            #+#    #+#             */
/*   Updated: 2024/06/24 14:21:46 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

int main( void )
{
	ClapTrap A("\033[1;35mClap\033[0m");
	ScavTrap B("\033[1;31mScav\033[0m");
	FragTrap C("\033[1;34mFrag\033[0m");
	B.guardGate();
	C.highFive();
	C.attack("target");
	C.beRepaired(2);
}