/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:42:53 by pgros             #+#    #+#             */
/*   Updated: 2023/06/02 16:07:34 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

//constructors and destructors
PresidentialPardonForm::PresidentialPardonForm() :
	AForm("Presidential Pardon form", 25, 5)
{
	std::cout << GREEN << "Default constructor of PresidentialPardonForm called." << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("Presidential Pardon form", 25, 5),
	_target(target)
{
	std::cout << GREEN << "Parameters constructor of PresidentialPardonForm called." << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm(other),
	_target(other.getTarget())
{
(void)other;
	std::cout << GREEN << "Copy constructor of PresidentialPardonForm called." << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << GREEN << "Destructor of PresidentialPardonForm called." << RESET << std::endl;
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

void PresidentialPardonForm::launchExecution(Bureaucrat const &executor) const
{
	(void)executor;
	std::cout << "presidential execution" << std::endl;
}