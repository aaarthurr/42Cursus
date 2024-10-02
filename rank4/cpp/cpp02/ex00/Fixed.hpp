/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:55:18 by arpages           #+#    #+#             */
/*   Updated: 2024/06/18 13:22:11 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <limits>

class Fixed
{
private:
    int     rawBits;
    static const int bits = 8;
public:
    Fixed(/* args */);
    Fixed(const Fixed &copy);

    Fixed &operator=(const Fixed &copy);
    
    ~Fixed();

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

#endif