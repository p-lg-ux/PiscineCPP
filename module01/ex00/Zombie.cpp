/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:55:59 by pgros             #+#    #+#             */
/*   Updated: 2023/03/31 19:33:39 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

//constructors and destructors
Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "Constructor of Zombie called with name: " << name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Destructor of Zombie named " << this->name << " called." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}