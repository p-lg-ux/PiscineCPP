/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:09:41 by pgros             #+#    #+#             */
/*   Updated: 2023/04/26 14:13:01 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

//constructors and destructors
DiamondTrap::DiamondTrap()
{
	std::cout << "Default constructor of DiamondTrap called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : 
	ClapTrap(name + "_clap_name"),
	ScavTrap(name + "_clap_name"),
	FragTrap(name + "_clap_name"),
	_name(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(30);
	std::cout << "String constructor of DiamondTrap called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : FragTrap(other)
{
	std::cout << "Copy constructor of DiamondTrap called." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor of DiamondTrap called." << std::endl;
}

//overloads
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	FragTrap::operator=(rhs);
	return *this;
}

std::string	DiamondTrap::getName() const
{
	return (DiamondTrap::_name);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << std::endl << "I am DiamondTrap " << DiamondTrap::_name ;
	std::cout << ". My ClapTrap name is " << this->FragTrap::getName() << "." << std::endl;
}

