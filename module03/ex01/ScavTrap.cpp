/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:26:33 by pgros             #+#    #+#             */
/*   Updated: 2023/04/23 18:34:24 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <string>

//constructors and destructors
ScavTrap::ScavTrap()
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "Default constructor of ScavTrap called." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "String constructor of ScavTrap called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	this->setName(other.getName());
	this->setHitPoints(other.getHitPoints());
	this->setEnergyPoints(other.getEnergyPoints());
	this->setAttackDamage(other.getAttackDamage());
	std::cout << "Copy constructor of ScavTrap called." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor of ScavTrap called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	this->setName(rhs.getName());
	this->setHitPoints(rhs.getHitPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setAttackDamage(rhs.getAttackDamage());
	return *this;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << std::endl << "ScavTrap " << this->getName();
		std::cout << " attacks " << target;
		std::cout << ", causing " << this->getAttackDamage();
		std::cout << " points of damage!" << std::endl;
		_energyPoints--;
		std::cout << this->getEnergyPoints();
		std::cout << " energy points left." << std::endl;
	}
	else
	{
		std::cout << std::endl << "ScavTrap " << this->getName();
		std::cout << " can't attack." << std::endl;
		if (_energyPoints <= 0)
			std::cout << this->getEnergyPoints() << " energy point left." << std::endl;
		if (_hitPoints <= 0)
			std::cout << this->getHitPoints() << " hit point left." << std::endl;
	}
}

void 	ScavTrap::guardGate()
{
	std::cout << std::endl << "ScavTrap " << this->getName();
	std::cout << " entered Gate keeper mode." << std::endl;
}
