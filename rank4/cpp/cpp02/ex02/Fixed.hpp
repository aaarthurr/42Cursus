/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:55:18 by arpages           #+#    #+#             */
/*   Updated: 2024/06/20 16:12:07 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

class Fixed
{
private:
    int                 rawBits;
    static const int    decimalBits = 8;
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &copy);

    Fixed &operator=(const Fixed &copy);

    bool operator>(const Fixed &comp) const;
    bool operator<(const Fixed &comp) const;
    bool operator>=(const Fixed &comp) const;
    bool operator<=(const Fixed &comp) const;
    bool operator==(const Fixed &comp) const;
    bool operator!=(const Fixed &comp) const;

    Fixed operator+(const Fixed &copy) const;
    Fixed operator-(const Fixed &copy) const;
    Fixed operator*(const Fixed &copy) const;
	Fixed operator/(const Fixed &copy) const;

	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

	static Fixed min(Fixed &a, Fixed &b);
	static const Fixed min(const Fixed &a, const Fixed &b);
	static Fixed max(Fixed &a, Fixed &b);
	static const Fixed max(const Fixed &a, const Fixed &b);
    
    ~Fixed();

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif