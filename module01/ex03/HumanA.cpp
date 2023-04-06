/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:41:54 by pgros             #+#    #+#             */
/*   Updated: 2023/04/05 16:39:12 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>
#include <string>


//constructors and destructors
HumanA::HumanA(std::string name, Weapon& weapon) :
	_name(name),
	_weapon(weapon)
{
	//std::cout << "Default constructor of HumanA called." << std::endl;
}

HumanA::~HumanA()
{
	//std::cout << "Destructor of HumanA called." << std::endl;
}

void	HumanA::setWeapon(Weapon& weapon)
{
	this->_weapon = weapon;
}

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
