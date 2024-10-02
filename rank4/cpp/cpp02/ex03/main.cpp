/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:48:55 by arpages           #+#    #+#             */
/*   Updated: 2024/06/20 20:17:31 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>
int main( void )
{
	Point a(1, 1);
	Point b(3, 1);
	Point c(3, 3);
	std::cout << "triangle coordonates : a = (1;1) b = (3;1) c = (3;3)" << std::endl;
	Point p1(1, 2);
	std::cout << "point at (1;2) :" << bsp(a, b, c, p1) << std::endl;
	Point p2(2, 2);
	std::cout << "point at (1;2) :" << bsp(a, b, c, p2) << std::endl;
	Point p3(2.5f , 2);
	std::cout << "point at (1;2) :" << bsp(a, b, c, p3) << std::endl;
    return 0;
}