/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:56:42 by arpages           #+#    #+#             */
/*   Updated: 2024/06/20 19:37:19 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*          constructeurs -- destructeurs           */

Fixed::Fixed(/* args */) :rawBits(0) 
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) :rawBits(value * 256)
{
    //std::cout << "Int constructor called with " << value << std::endl;
}

Fixed::Fixed(const float value) :rawBits(roundf(value * 256.0f))
{
    //std::cout << "Float constructor called with " << value << std::endl;
}

Fixed::Fixed( const Fixed &copy )  {
    //std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

/*          operateur de copie                  */

Fixed& Fixed::operator=( const Fixed &copy )
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->rawBits = copy.getRawBits();
    return *this;
}

/*          operateurs de comparaisons          */

bool Fixed::operator>(const Fixed &comp) const
{
    return (this->getRawBits() > comp.getRawBits());
}

bool Fixed::operator<(const Fixed &comp) const
{
    return (this->getRawBits() < comp.getRawBits());
}

bool Fixed::operator>=(const Fixed &comp) const
{
    return (this->getRawBits() >= comp.getRawBits());
}

bool Fixed::operator<=(const Fixed &comp) const
{
    return (this->getRawBits() <= comp.getRawBits());
}

bool Fixed::operator==(const Fixed &comp) const
{
    return (this->getRawBits() == comp.getRawBits());
}

bool Fixed::operator!=(const Fixed &comp) const
{
    return (this->getRawBits() != comp.getRawBits());
}

/*          operateurs d'arithmetiques          */

Fixed   Fixed::operator+(const Fixed &op) const
{
    return (Fixed(this->toFloat() + op.toFloat()));
}

Fixed   Fixed::operator-(const Fixed &op) const
{
    return (Fixed(this->toFloat() - op.toFloat()));
}

Fixed   Fixed::operator/(const Fixed &op) const
{
    if (op.getRawBits() == 0)
	{
        std::cout << "\033[0;31mERROR : Division by 0\033[0m" << std::endl;
		exit(1);
	}
    return (Fixed(this->toFloat() / op.toFloat()));
}

Fixed   Fixed::operator*(const Fixed &op) const
{
    return (Fixed(this->toFloat() * op.toFloat()));
}

/*          operateurs d'incrementations        */

Fixed   &Fixed::operator++(void)
{
    ++this->rawBits;
    return (*this);
    
}

Fixed   Fixed::operator++( int ) {
    Fixed tmp( *this );
    tmp.rawBits = this->rawBits++;
    return tmp;
}

Fixed   &Fixed::operator--(void)
{
    --this->rawBits;
    return (*this);
    
}

Fixed   Fixed::operator--( int ) {
    Fixed tmp( *this );
    tmp.rawBits = this->rawBits--;
    return tmp;
}

/*          extremes                            */

Fixed Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

const Fixed Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

const Fixed Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

/*          methodes internes                   */

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member fonction called" << std::endl;
    return(this->rawBits);
}

void    Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member fonction called" << std::endl;
    this->rawBits = raw;
}

float  Fixed::toFloat(void) const
{
    return(this->rawBits / 256.0f);
}

int Fixed::toInt(void) const
{
    return(roundf(this->rawBits / 256.0f));
}

/*          typeshit                        */

std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
    o << i.toFloat();
    return o;
}