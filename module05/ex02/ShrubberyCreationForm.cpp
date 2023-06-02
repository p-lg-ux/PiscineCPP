/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:36:30 by pgros             #+#    #+#             */
/*   Updated: 2023/06/02 16:07:42 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

//constructors and destructors
ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Shrubbery Creation form", 145, 137)
{
	std::cout << GREEN << "Default constructor of ShrubberyCreationForm called." << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("Shrubbery Creation form", 145, 137),
	_target(target)
{
	std::cout << GREEN << "Parameters constructor of ShrubberyCreationForm called." << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other),
	_target(other.getTarget())
{
(void)other;
	std::cout << GREEN << "Copy constructor of ShrubberyCreationForm called." << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << GREEN << "Destructor of ShrubberyCreationForm called." << RESET << std::endl;
}

//overloads
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
(void)rhs;
	return *this;
}

//getters
const std::string	&ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void ShrubberyCreationForm::launchExecution(Bureaucrat const &executor) const
{
	(void)executor;
	std::cout << "shrubbery execution" << std::endl;
}
