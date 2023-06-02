/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:40:31 by pgros             #+#    #+#             */
/*   Updated: 2023/06/02 16:07:46 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <string>

//constructors and destructors
RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Robotomy Request form", 72, 45)
{
	std::cout << GREEN << "Default constructor of RobotomyRequestForm called." << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("Robotomy Request form", 72, 45),
	_target(target)
{
	std::cout << GREEN << "Parameters constructor of RobotomyRequestForm called." << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other),
	_target(other.getTarget())
{
(void)other;
	std::cout << GREEN << "Copy constructor of RobotomyRequestForm called." << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << GREEN << "Destructor of RobotomyRequestForm called." << RESET << std::endl;
}

//overloads
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
(void)rhs;
	return *this;
}

//getters
const std::string	&RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void RobotomyRequestForm::launchExecution(Bureaucrat const &executor) const
{
	(void)executor;
	std::cout << "robotomy execution" << std::endl;
}