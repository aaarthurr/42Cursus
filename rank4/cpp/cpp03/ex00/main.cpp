/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:27:40 by arthur            #+#    #+#             */
/*   Updated: 2024/06/23 20:18:00 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

int main( void )
{
	ClapTrap A("\033[1;35mClap\033[0m");
	A.attack("a target");
	A.beRepaired(1);
	A.takeDamage(10);
	ClapTrap B("BBB");
	B.attack("another target");
	B.takeDamage(5);
	A.takeDamage(5);
}