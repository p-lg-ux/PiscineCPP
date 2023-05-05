/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:49:21 by pgros             #+#    #+#             */
/*   Updated: 2023/05/05 15:52:25 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>
#include <string>

//constructors and destructors
WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "Default constructor of WrongCat called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
	_type = other.getType();
	std::cout << "Copy constructor of WrongCat called." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor of WrongCat called." << std::endl;
}

//overloads
WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	_type = rhs.getType();
	return *this;
}

void	WrongCat::makeSound(void) const
{
	std::cout << getType() << " goes meow." << std::endl;
}