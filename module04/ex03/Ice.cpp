/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:18:54 by pgros             #+#    #+#             */
/*   Updated: 2023/05/12 17:07:05 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << GREEN << "Default constructor of Ice called." << RESET << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << GREEN << "Copy constructor of Ice called." << RESET << std::endl;
}

Ice::~Ice()
{
	std::cout << GREEN << "Destructor of Ice called." << RESET << std::endl;
}

Ice& Ice::operator=(const Ice &rhs)
{
	_type = rhs.getType();
	return (*this);
}

AMateria* Ice::clone() const
{
	AMateria *newMateria = new Ice();
	return (newMateria);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
