/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:35:35 by pgros             #+#    #+#             */
/*   Updated: 2023/05/12 20:22:21 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
/*
public:
		AMateria();
		AMateria(const AMateria &other);
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria& operator=(const AMateria &rhs);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);*/


AMateria::AMateria()
{
	std::cout << GREEN << "Default constructor of AMateria called." << RESET << std::endl;
	_type = "";
}

AMateria::AMateria(const AMateria &other) : _type(other.getType())
{
	std::cout << GREEN << "Copy constructor of AMateria called." << RESET << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << GREEN << "String constructor of AMateria called." << RESET << std::endl;
}

AMateria::~AMateria()
{
	std::cout << GREEN << "Destructor of AMateria called." << RESET << std::endl;
}

AMateria& AMateria::operator=(const AMateria &rhs)
{
	_type = rhs.getType();
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (_type);
}


void AMateria::use(ICharacter& target)
{
	std::cout << "* use Materia against " << target.getName() << " *" << std::endl;
	return;
}