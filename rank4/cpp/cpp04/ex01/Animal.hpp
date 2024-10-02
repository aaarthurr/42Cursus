/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:25:32 by arthur            #+#    #+#             */
/*   Updated: 2024/06/24 19:11:37 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

#include "Brain.hpp"

class Animal
{
protected:
    std::string _type;

public:
    Animal( void );
    Animal( std::string type );
    virtual ~Animal( void );

    Animal( const Animal& src );
    Animal& operator=( const Animal& rhs );

    virtual void    makeSound( void ) const;
    std::string     getType( void ) const; 
};