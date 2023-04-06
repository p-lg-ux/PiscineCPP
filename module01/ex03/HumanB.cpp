/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:41:54 by pgros             #+#    #+#             */
/*   Updated: 2023/04/05 16:47:15 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>
#include <string>


//constructors and destructors
HumanB::HumanB(std::string name) :
	_name(name)
{
	this->_weapon = NULL;
	//std::cout << "Default constructor of HumanB called." << std::endl;
}

HumanB::~HumanB()
{
	//std::cout << "Destructor of HumanB called." << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void) const
{
	if (this->_weapon != NULL)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " can't attack" << std::endl;
}
