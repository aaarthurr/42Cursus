/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:52:31 by arpages           #+#    #+#             */
/*   Updated: 2024/06/15 12:30:52 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <limits>

int main(void)
{
    
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;
    
    std::cout << "string address ->\t" << &string << std::endl;
    std::cout << "PTR address ->\t\t" << stringPTR << std::endl;
    std::cout << "REF address ->\t\t" << &stringREF << std::endl;
    std::cout << "-- -- -- -- -- --" << std::endl;
    std::cout << "string  ->\t\t" << string << std::endl;
    std::cout << "Value of PTR ->\t\t" << *stringPTR << std::endl;
    std::cout << "Value of REF ->\t\t" << stringREF << std::endl;
    
}