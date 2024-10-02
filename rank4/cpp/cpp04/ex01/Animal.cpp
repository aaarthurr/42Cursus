/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:25:30 by arthur            #+#    #+#             */
/*   Updated: 2024/06/24 17:45:18 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : _type( "Animal" ) {
    std::cout << this->_type << " basic constructor called" << std::endl;
}

Animal::Animal( std::string type ) : _type( type )
{
    std::cout << "Animal " << this->_type << " constructor called" << std::endl;
}

Animal::~Animal( void )
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal( const Animal& src )
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal& Animal::operator=( const Animal& rhs )
{
    std::cout << "Animal assignment operator called" << std::endl;
    if ( this != &rhs ) {
        this->_type = rhs._type;
    }
    return *this;
}

void Animal::makeSound( void ) const
{
    std::cout << "An animal sound" << std::endl;
}

std::string    Animal::getType( void ) const
{
    return this->_type;
}