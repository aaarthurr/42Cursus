/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:28:51 by arthur            #+#    #+#             */
/*   Updated: 2024/06/16 15:12:55 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "\033[0;36m" << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl; 
	std::cout << "I really do! (debug)" << "\033[0m"<< std::endl;
}

void Harl::info(void)
{
	std::cout << "\033[0;32m" << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger." << std::endl; 
	std::cout << "If you did, I wouldn't be asking for more! (info)" << "\033[0m"<< std::endl;
}

void Harl::warning(void)
{
	std::cout << "\033[0;33m" << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "i've been coming foryears whereas you "; 
	std::cout << "started working here since last month. (warning)" << "\033[0m"<< std::endl;
}

void Harl::error(void)
{
	std::cout << "\033[0;31m" <<"This is unacceptable!" << std::endl;
	std::cout << "I want to speak to the manager now. (error)" << "\033[0m"<< std::endl;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*ptr_complain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*ptr_complain[i])();
			break ;
		}
	}
}