/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:26:33 by pgros             #+#    #+#             */
/*   Updated: 2023/04/25 13:18:06 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <string>

//constructors and destructors
FragTrap::FragTrap()
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "Default constructor of FragTrap called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "String constructor of FragTrap called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
	this->setName(other.getName());
	this->setHitPoints(other.getHitPoints());
	this->setEnergyPoints(other.getEnergyPoints());
	this->setAttackDamage(other.getAttackDamage());
	std::cout << "Copy constructor of FragTrap called." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor of FragTrap called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	this->setName(rhs.getName());
	this->setHitPoints(rhs.getHitPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setAttackDamage(rhs.getAttackDamage());
	return *this;
}

void	FragTrap::highFiveGuys()
{
	std::cout << std::endl << "FragTrap " << this->getName();
	std::cout << " asks for a high five." << std::endl;
}
