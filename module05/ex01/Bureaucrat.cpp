/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:42:21 by pgros             #+#    #+#             */
/*   Updated: 2023/05/30 16:38:56 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

//constructors and destructors
Bureaucrat::Bureaucrat()
{
	std::cout << GREEN << "Default constructor of Bureaucrat called." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : 
	_name(other.getName()),
	_grade(other.getGrade())
{
	std::cout << GREEN << "Copy constructor of Bureaucrat called." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
	std::cout << GREEN << "Parameters constructor of Bureaucrat called." << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << GREEN << "Destructor of Bureaucrat called." << RESET << std::endl;
}

//overloads
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	_grade = rhs.getGrade();
	return *this;
}

const std::string& 	Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::upgrade()
{
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::downgrade()
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat& val)
{
	os << val.getName() << ", bureaucrat grade " << val.getGrade() << ".";
	return os;
}