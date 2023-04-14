/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:35:36 by pgros             #+#    #+#             */
/*   Updated: 2023/04/07 17:09:37 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

//constructors and destructors
Harl::Harl()
{
	//std::cout << "Default constructor of Harl called." << std::endl;
}

Harl::~Harl()
{
	//std::cout << "Destructor of Harl called." << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout << "I really do !" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger ! ";
	std::cout << "If you did, I wouldn’t be asking for more !" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working here";
	std::cout << " since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." ;
	std::cout << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string		levels[] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};
	ComplainFunc	f[] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};

	int i = 0;
	while (i < 4)
	{
		if (level == levels[i])
			(this->*f[i])();
		i++;
	}
}
