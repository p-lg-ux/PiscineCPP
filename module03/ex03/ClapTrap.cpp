/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:03:47 by pgros             #+#    #+#             */
/*   Updated: 2023/04/23 18:08:00 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

//constructors and destructors
ClapTrap::ClapTrap()
{
	this->setHitPoints(10);
	this->setEnergyPoints(10);
	this->setAttackDamage(0);
	std::cout << "Default constructor of ClapTrap called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	this->setHitPoints(10);
	this->setEnergyPoints(10);
	this->setAttackDamage(0);
	std::cout << "String constructor of ClapTrap called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	this->setName(other.getName());
	this->setHitPoints(other.getHitPoints());
	this->setEnergyPoints(other.getEnergyPoints());
	this->setAttackDamage(other.getAttackDamage());
	std::cout << "Copy constructor of ClapTrap called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor of ClapTrap called." << std::endl;
}

//overloads
ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	this->setName(rhs.getName());
	this->setHitPoints(rhs.getHitPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setAttackDamage(rhs.getAttackDamage());
	return *this;
}

//getters
std::string		ClapTrap::getName() const
{
	return (_name);
}

unsigned int	ClapTrap::getHitPoints() const
{
	return (_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return (_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}

//setters
void	ClapTrap::setName(std::string name)
{
	_name = name;
}

void	ClapTrap::setHitPoints(unsigned int amount)
{
	_hitPoints = amount;
}

void	ClapTrap::setEnergyPoints(unsigned int amount)
{
	_energyPoints = amount;
}

void	ClapTrap::setAttackDamage(unsigned int amount)
{
	_attackDamage = amount;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << std::endl << "ClapTrap " << this->getName();
		std::cout << " attacks " << target;
		std::cout << ", causing " << this->getAttackDamage();
		std::cout << " points of damage!" << std::endl;
		_energyPoints--;
		std::cout << this->getEnergyPoints();
		std::cout << " energy points left." << std::endl;
	}
	else
	{
		std::cout << std::endl << "ClapTrap " << this->getName();
		std::cout << " can't attack." << std::endl;
		if (_energyPoints <= 0)
			std::cout << this->getEnergyPoints() << " energy point left." << std::endl;
		if (_hitPoints <= 0)
			std::cout << this->getHitPoints() << " hit point left." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << std::endl << "ClapTrap " << this->getName();
	std::cout << " takes " << amount;
	std::cout << " damage." << std::endl;
	if (amount < _hitPoints)
		_hitPoints -= amount;
	else
		_hitPoints = 0;
	std::cout << this->getHitPoints();
	std::cout << " hit points left." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << std::endl << "ClapTrap " << this->getName();
		std::cout << " is repaired and gains " << amount << " hit points.";
		_hitPoints += amount;
		std::cout << " Total hit points: " << this->getHitPoints() << std::endl;
		_energyPoints--;
		std::cout << this->getEnergyPoints();
		std::cout << " energy points left." << std::endl;
	}
	else
	{
		std::cout << std::endl << "ClapTrap " << this->getName();
		std::cout << " can't be repaired." << std::endl;
		if (_energyPoints <= 0)
			std::cout << this->getEnergyPoints() << " energy point left." << std::endl;
		if (_hitPoints <= 0)
			std::cout << this->getHitPoints() << " hit point left." << std::endl;
	}
}