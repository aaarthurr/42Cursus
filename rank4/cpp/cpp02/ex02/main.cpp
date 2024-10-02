/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:48:55 by arpages           #+#    #+#             */
/*   Updated: 2024/06/20 19:37:48 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "my test" << std::endl;
	a = 1.250f;
	std::cout << a << " " << b << std::endl;
	std::cout << "addition : " << a + b << std::endl;
	std::cout << "add 10 : " << a + 10 << std::endl;
	std::cout << "divide by 2 : " << a / 2 << std::endl;
	std::cout << "substract 5 : " << a - 5 << std::endl;
	std::cout << "multiply by 1.2 : " << a * 1.2f << std::endl;
    return 0;
}