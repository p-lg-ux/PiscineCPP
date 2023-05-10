/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:41:10 by pgros             #+#    #+#             */
/*   Updated: 2023/05/10 16:44:40 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Default constructor of Cure called." << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << "Copy constructor of Cure called." << std::endl;
}

Cure::~Cure()
{
	std::cout << "Destructor of Cure called." << std::endl;
}

Cure& Cure::operator=(const Cure &rhs)
{
	_type = rhs._type;
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