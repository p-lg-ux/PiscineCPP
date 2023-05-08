/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:22:31 by pgros             #+#    #+#             */
/*   Updated: 2023/05/08 18:02:44 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
#include <string>

//constructors and destructors
Dog::Dog()
{
	std::cout << "Default constructor of Dog called." << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog& other)
{
	std::cout << "Copy constructor of Dog called." << std::endl;
	_type = other.getType();
	_brain = new Brain();
	*_brain = *(other._brain);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Destructor of Dog called." << std::endl;
}

//overloads
Dog& Dog::operator=(const Dog& rhs)
{
	_type = rhs.getType();
	*_brain = *(rhs._brain);
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << getType() << " goes woof." << std::endl;
}

Brain	*Dog::getBrainAddress(void) const
{
	return (_brain);
}
