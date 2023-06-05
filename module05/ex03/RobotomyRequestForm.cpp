/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:40:31 by pgros             #+#    #+#             */
/*   Updated: 2023/06/05 16:10:24 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
# define INVERSE	"\x1b[7m"

//constructors and destructors
RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Robotomy Request form", 72, 45)
{
	std::cout << INVERSE << "Default constructor of RobotomyRequestForm called." << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("Robotomy Request form", 72, 45),
	_target(target)
{
	std::cout << INVERSE << "Parameters constructor of RobotomyRequestForm called." << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other),
	_target(other.getTarget())
{
(void)other;
	std::cout << INVERSE << "Copy constructor of RobotomyRequestForm called." << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << INVERSE << "Destructor of RobotomyRequestForm called." << RESET << std::endl;
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

void RobotomyRequestForm::launchExecution() const
{
	std::cout << "*drilling noises* TATATATATATATATATA" << std::endl;
	if (rand() % 2)
		std::cout << getTarget() << " has successfully been robotomized :)" << std::endl;
	else
		std::cout << "The robotomy failed :(" << std::endl;
}