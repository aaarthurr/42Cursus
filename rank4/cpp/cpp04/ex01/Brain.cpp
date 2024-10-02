/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:34:56 by arthur            #+#    #+#             */
/*   Updated: 2024/06/24 19:33:25 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Created" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destroyed" << std::endl;
}

Brain::Brain(const Brain& src)
{
	*this = src;
	std::cout << "Brain copy contructor" << std::endl;
}

Brain& Brain::operator=(const Brain& src)
{
	std::cout << "Brain copy called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
		{
			this->_idea[i] = src._idea[i];
		}
	}
	return *this;
}