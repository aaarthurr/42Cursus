/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:14:12 by arthur            #+#    #+#             */
/*   Updated: 2024/06/25 15:28:22 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
private:
	
public:
	Ice(/* args */);
	~Ice();

	Ice(Ice const &);
	Ice& operator=(Ice const &);

	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target);
};

