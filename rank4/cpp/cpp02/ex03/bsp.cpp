/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:03:19 by arthur            #+#    #+#             */
/*   Updated: 2024/06/20 23:33:46 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed   abs(Fixed x) {
    if (x < 0)
        return (x * -1);
    return x;
}

static Fixed   area( Point const a, Point const b, Point const c )
{
	Fixed const A( a.getX() * ( b.getY() - c.getY() ) );
	Fixed const B( b.getX() * ( c.getY() - a.getY() ) );
	Fixed const C( c.getX() * ( a.getY() - b.getY() ) );
	Fixed const square(A + B + C);
    return (square / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const P) {
    Fixed   totalArea = abs(area( a, b, c ));
    Fixed   pabArea = abs(area( P, a, b ));
    Fixed   pbcArea = abs(area( P, b, c ));
    Fixed   pcaArea = abs(area( P, c, a ));

    return  ( totalArea == pabArea + pbcArea + pcaArea );
}