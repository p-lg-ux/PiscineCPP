/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:35:35 by pgros             #+#    #+#             */
/*   Updated: 2023/05/10 15:22:22 by pgros            ###   ########.fr       */
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
	std::cout << "Default constructor of AMateria called." << std::endl;
	_type = "";
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << "Copy constructor of AMateria called." << std::endl;
	_type = other._type;
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "String constructor of AMateria called." << std::endl;
	_type = type;
}

AMateria::~AMateria()
{
	std::cout << "Default destructor of AMateria called." << std::endl;
}

AMateria& AMateria::operator=(const AMateria &rhs)
{
	_type = rhs._type;
}

std::string const & AMateria::getType() const
{
	return (_type);
}
