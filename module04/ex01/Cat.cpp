/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:24:01 by pgros             #+#    #+#             */
/*   Updated: 2023/05/08 18:02:55 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <string>

//constructors and destructors
Cat::Cat()
{
	std::cout << "Default constructor of Cat called." << std::endl;
	_type = "Cat";
	_brain = new Brain();
}
Cat::Cat(const Cat& other)
{
	std::cout << "Copy constructor of Cat called." << std::endl;
	_type = other.getType();
	_brain = new Brain();
	*_brain = *(other._brain);
}
Cat::~Cat()
{
	delete _brain;
	std::cout << "Destructor of Cat called." << std::endl;
}
//overloads
Cat& Cat::operator=(const Cat& rhs)
{
	_type = rhs.getType();
	*_brain = *(rhs._brain);
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << getType() << " goes meow." << std::endl;
}

Brain	*Cat::getBrainAddress(void) const
{
	return (_brain);
}