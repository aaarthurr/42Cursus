/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:56:42 by arpages           #+#    #+#             */
/*   Updated: 2024/06/20 15:11:58 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(/* args */) :rawBits(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &copy )  {
    std::cout << "Copy constructor called" << std::endl;
    this->rawBits = copy.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=( const Fixed &copy ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->rawBits = copy.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member fonction called" << std::endl;
    return(this->rawBits);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member fonction called" << std::endl;
    this->rawBits = raw;
}
 