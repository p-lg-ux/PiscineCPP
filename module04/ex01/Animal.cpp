/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:15:35 by pgros             #+#    #+#             */
/*   Updated: 2023/05/05 16:08:19 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <string>

//constructors and destructors
Animal::Animal()
{
	std::cout << "Default constructor of Animal called." << std::endl;
}
Animal::Animal(const Animal& other)
{
	_type = other.getType();
	std::cout << "Copy constructor of Animal called." << std::endl;
}
Animal::~Animal()
{
	std::cout << "Destructor of Animal called." << std::endl;
}
//overloads
Animal& Animal::operator=(const Animal& rhs)
{
	_type = rhs.getType();
	return *this;
}

std::string	Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal makes no sound." << std::endl;
}
