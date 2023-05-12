/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:41:10 by pgros             #+#    #+#             */
/*   Updated: 2023/05/12 17:07:11 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << GREEN << "Default constructor of Cure called." << RESET << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << GREEN << "Copy constructor of Cure called." << RESET << std::endl;
}

Cure::~Cure()
{
	std::cout << GREEN << "Destructor of Cure called." << RESET << std::endl;
}

Cure& Cure::operator=(const Cure &rhs)
{
	_type = rhs.getType();
	return (*this);

}

AMateria* Cure::clone() const
{
	AMateria *newMateria = new Cure();
	return (newMateria);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}