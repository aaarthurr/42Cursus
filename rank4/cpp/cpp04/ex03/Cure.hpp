/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:14:05 by arthur            #+#    #+#             */
/*   Updated: 2024/06/25 15:27:34 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
private:
	
public:
	Cure(/* args */);
	~Cure();

	Cure(Cure const &);
	Cure& operator=(Cure const &);

	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target);
};

