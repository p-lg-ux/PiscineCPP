/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:32:14 by pgros             #+#    #+#             */
/*   Updated: 2023/05/05 15:52:02 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

//constructors and destructors
WrongAnimal::WrongAnimal()
{
	std::cout << "Default constructor of WrongAnimal called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	_type = other.getType();
	std::cout << "Copy constructor of WrongAnimal called." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor of WrongAnimal called." << std::endl;
}

//overloads
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	_type = rhs.getType();
	return *this;
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal makes no sound." << std::endl;
}