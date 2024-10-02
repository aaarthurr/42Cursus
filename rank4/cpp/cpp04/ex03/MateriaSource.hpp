/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:07:27 by arthur            #+#    #+#             */
/*   Updated: 2024/06/25 15:36:43 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* materias[4];
public:
	MateriaSource(/* args */);
	MateriaSource(MateriaSource const &);
	~MateriaSource();

	MateriaSource& operator=(MateriaSource const &);
	
	AMateria*	createMateria(std::string const & type);
	void		learnMateria(AMateria*);

	AMateria*	getMateria(std::string const &type);
};
