/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:36:32 by pgros             #+#    #+#             */
/*   Updated: 2023/04/04 17:39:45 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>
#include <string>

//constructors and destructors
Weapon::Weapon(std::string type) : _type(type)
{
	//std::cout << "Default constructor of Weapon called." << std::endl;
}

Weapon::~Weapon()
{
	//std::cout << "Destructor of Weapon called." << std::endl;
}

const std::string&	Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
