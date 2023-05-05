/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:24:01 by pgros             #+#    #+#             */
/*   Updated: 2023/05/05 11:55:29 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <string>

//constructors and destructors
Cat::Cat()
{
	_type = "Cat";
	std::cout << "Default constructor of Cat called." << std::endl;
}
Cat::Cat(const Cat& other)
{
	_type = other.getType();
	std::cout << "Copy constructor of Cat called." << std::endl;
}
Cat::~Cat()
{
	std::cout << "Destructor of Cat called." << std::endl;
}
//overloads
Cat& Cat::operator=(const Cat& rhs)
{
	_type = rhs.getType();
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << getType() << " goes meow." << std::endl;
}