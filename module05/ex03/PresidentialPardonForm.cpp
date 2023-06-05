/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:42:53 by pgros             #+#    #+#             */
/*   Updated: 2023/06/05 16:10:11 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>
# define INVERSE	"\x1b[7m"

//constructors and destructors
PresidentialPardonForm::PresidentialPardonForm() :
	AForm("Presidential Pardon form", 25, 5)
{
	std::cout << INVERSE << "Default constructor of PresidentialPardonForm called." << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("Presidential Pardon form", 25, 5),
	_target(target)
{
	std::cout << INVERSE << "Parameters constructor of PresidentialPardonForm called." << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm(other),
	_target(other.getTarget())
{
(void)other;
	std::cout << INVERSE << "Copy constructor of PresidentialPardonForm called." << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << INVERSE << "Destructor of PresidentialPardonForm called." << RESET << std::endl;
}

//overloads
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
(void)rhs;
	return *this;
}

//getters
const std::string	&PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void PresidentialPardonForm::launchExecution() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}