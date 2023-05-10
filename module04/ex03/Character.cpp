/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:54:38 by pgros             #+#    #+#             */
/*   Updated: 2023/05/10 16:54:07 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
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
	std::cout << "Default constructor of Character called." << std::endl;
	_name = "";
	for (int i=0; i<4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(const Character &other)
{
	std::cout << "Copy constructor of Character called." << std::endl;
	for (int i=0; i<4; i++)
	{
		if (other.getItem(i) == NULL)
			_inventory[i] = NULL;
		else
		{
			_inventory[i] = new AMateria()
		}
	}
}

Character::Character(std::string name)
{
	std::cout << "String constructor of Character called." << std::endl;
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
		delete _inventory[i];
	}
	std::cout << "Destructor of Character called." << std::endl;
}

