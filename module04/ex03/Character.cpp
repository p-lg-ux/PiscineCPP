/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:54:38 by pgros             #+#    #+#             */
/*   Updated: 2023/05/15 17:06:23 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
 /*
private:
		std::string	_name;
		AMateria	*_inventory[4];

	public:
		Character();
		Character(const Character &other);
		Character(std::string name);
		~Character();
		Character&	operator=(const Character &rhs);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		AMateria *getItem(int idx) const;
		*/

Character::Character()
{
	std::cout << GREEN << "Default constructor of Character called." << RESET << std::endl;
	_name = "";
	for (int i=0; i<4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(const Character &other)
{
	std::cout << GREEN << "Copy constructor of Character called." << RESET << std::endl;
	_name = other.getName();
	for (int i=0; i<4; i++)
	{
		if (other.getItem(i) == NULL)
			_inventory[i] = NULL;
		else
			_inventory[i] = other.getItem(i)->clone();
	}
}

Character::Character(std::string name)
{
	std::cout << GREEN << "String constructor of Character called." << RESET << std::endl;
	_name = name;
	for (int i=0; i<4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::~Character()
{
	for (int i=0; i<4; i++)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
		_inventory[i] = NULL;
	}
	std::cout << GREEN << "Destructor of Character " << getName() << " called." << RESET << std::endl;
}

Character&	Character::operator=(const Character &rhs)
{
	std::cout << GREEN << "Assignment of Character " << getName() << " called." << RESET << std::endl;
	_name = rhs.getName();
	for (int i=0; i<4; i++)
	{
		delete _inventory[i];
		if (rhs.getItem(i) == NULL)
			_inventory[i] = NULL;
		else
			_inventory[i] = rhs.getItem(i)->clone();
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	for (int i=0; i<4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			break;
		}	
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return;
	if (_inventory[idx] != NULL)
		_inventory[idx]->use(target);
}

AMateria *Character::getItem(int idx) const
{
	if (idx < 0 || idx > 3)
		return NULL;
	return (_inventory[idx]);
}
