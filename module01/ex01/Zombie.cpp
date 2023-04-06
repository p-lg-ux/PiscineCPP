/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:55:59 by pgros             #+#    #+#             */
/*   Updated: 2023/04/03 15:52:35 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

//constructors and destructors
Zombie::Zombie()
{
	std::cout << "Default constructor of Zombie called." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Constructor of Zombie called with name: " << name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Destructor of Zombie named " << this->_name << " called." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}