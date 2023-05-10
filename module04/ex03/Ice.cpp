/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:18:54 by pgros             #+#    #+#             */
/*   Updated: 2023/05/10 16:44:33 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Default constructor of Ice called." << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "Copy constructor of Ice called." << std::endl;
}

Ice::~Ice()
{
	std::cout << "Destructor of Ice called." << std::endl;
}

Ice& Ice::operator=(const Ice &rhs)
{
	_type = rhs._type;
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
