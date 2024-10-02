/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:30:52 by arthur            #+#    #+#             */
/*   Updated: 2024/06/25 15:30:01 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

class Character : public ICharacter
{
private:
	AMateria	*_inventory[4];
	std::string	_name;
public:
	Character(std::string const &name);
	Character(Character const &src);
	~Character();
	
	Character&	operator=(Character const &rhs);

	std::string const & getName() const;
	void		equip(AMateria* m);
	void		unequip(int idx);
	void		use(int idx, ICharacter& target);
};

