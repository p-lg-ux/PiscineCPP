/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:22:31 by pgros             #+#    #+#             */
/*   Updated: 2023/05/05 12:38:34 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
#include <string>

//constructors and destructors
Dog::Dog()
{
	_type = "Dog";
	std::cout << "Default constructor of Dog called." << std::endl;
}

Dog::Dog(const Dog& other)
{
	_type = other.getType();
	std::cout << "Copy constructor of Dog called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor of Dog called." << std::endl;
}

//overloads
Dog& Dog::operator=(const Dog& rhs)
{
	_type = rhs.getType();
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << getType() << " goes woof." << std::endl;
}