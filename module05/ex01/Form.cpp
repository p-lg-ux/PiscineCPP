/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:40:50 by pgros             #+#    #+#             */
/*   Updated: 2023/06/01 20:04:55 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
#include <string>

//constructors and destructors
Form::Form() : _sign_grade(1), _exec_grade(1)
{
	_is_signed = false;
	std::cout << GREEN << "Default constructor of Form called." << RESET << std::endl;
}

Form::Form(const Form& other) : 
	_name(other.getName()),
	_sign_grade(other.getSignGrade()),
	_exec_grade(other.getExecGrade())
{
	_is_signed = false;
	std::cout << GREEN << "Copy constructor of Form called." << RESET << std::endl;
}

Form::Form(std::string name, int sign_grade, int exec_grade) :
	_name(name),
	_sign_grade(sign_grade),
	_exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
	_is_signed = false;
	std::cout << GREEN << "Parameters constructor of Form called." << RESET << std::endl;
}

Form::~Form()
{
	std::cout << GREEN << "Destructor of Form called." << RESET << std::endl;
}

//overloads
Form& Form::operator=(const Form& rhs)
{
	(void)rhs;
	return *this;
}

//getters
const std::string 	&Form::getName() const
{
	return (_name);
}

int	Form::getSignGrade() const
{
	return (_sign_grade);
}

int	Form::getExecGrade() const
{
	return (_exec_grade);
}

bool Form::isSigned() const
{
	return (_is_signed);
}

//member functions
void Form::beSigned(Bureaucrat &guy)
{
	if (guy.getGrade() <= _sign_grade)
		_is_signed = true;
	else
		throw Form::GradeTooLowException();
}

//exceptions
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form exception: grade is too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form exception: grade is too low.");
}

//stream redirection
std::ostream &operator<<(std::ostream &os, const Form& val)
{
	os << "form " << val.getName() << ":" << std::endl;
	os << "\tsign grade:\t" << val.getSignGrade() << std::endl;
	os << "\texec grade:\t" << val.getExecGrade() << std::endl;
	os << "\tstate:\t\t";
	if (val.isSigned())
		os << "✅ signed";
	else
		os << "❌ not signed";
	return os;
}