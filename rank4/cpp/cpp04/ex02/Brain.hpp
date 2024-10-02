/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:34:59 by arthur            #+#    #+#             */
/*   Updated: 2024/06/24 19:07:16 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

class Brain
{
private:
	std::string _idea[100];
public:
	Brain();
	~Brain();
	Brain(const Brain& src);
	Brain& operator=(const Brain& rhs);
};

