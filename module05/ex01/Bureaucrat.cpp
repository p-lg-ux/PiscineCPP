/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:42:21 by pgros             #+#    #+#             */
/*   Updated: 2023/06/01 19:51:10 by pgros            ###   ########.fr       */
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

void Bureaucrat::signForm(Form &form)
{
	if (form.isSigned())
	{
		std::cout << this->getName();
		std::cout << " couldn't sign " << form.getName();
		std::cout << " because it's already signed." << std::endl;
	}
	try
	{
		form.beSigned(*this);
		std::cout << this->getName();
		std::cout << " signed " << form.getName() << "." << std::endl;
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cout << this->getName();
		std::cout << " couldn't sign " << form.getName();
		std::cout << " because her/his grade was too low." << std::endl;
	}
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat exception: grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat exception: grade is too low.");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat& val)
{
	os << val.getName() << ", bureaucrat grade " << val.getGrade() << ".";
	return os;
}