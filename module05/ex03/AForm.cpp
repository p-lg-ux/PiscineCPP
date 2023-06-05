/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:40:50 by pgros             #+#    #+#             */
/*   Updated: 2023/06/05 16:06:41 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include <string>

//constructors and destructors
AForm::AForm() : _sign_grade(1), _exec_grade(1)
{
	_is_signed = false;
	std::cout << INVERSE << "Default constructor of AForm called." << RESET << std::endl;
}

AForm::AForm(const AForm& other) : 
	_name(other.getName()),
	_sign_grade(other.getSignGrade()),
	_exec_grade(other.getExecGrade())
{
	_is_signed = false;
	std::cout << INVERSE << "Copy constructor of AForm called." << RESET << std::endl;
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) :
	_name(name),
	_sign_grade(sign_grade),
	_exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw AForm::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw AForm::GradeTooLowException();
	_is_signed = false;
	std::cout << INVERSE << "Parameters constructor of AForm called." << RESET << std::endl;
}

AForm::~AForm()
{
	std::cout << INVERSE << "Destructor of AForm called." << RESET << std::endl;
}

//overloads
AForm& AForm::operator=(const AForm& rhs)
{
	(void)rhs;
	return *this;
}

//getters
const std::string 	&AForm::getName() const
{
	return (_name);
}

int	AForm::getSignGrade() const
{
	return (_sign_grade);
}

int	AForm::getExecGrade() const
{
	return (_exec_grade);
}

bool AForm::isSigned() const
{
	return (_is_signed);
}

//member functions
void AForm::beSigned(Bureaucrat &guy)
{
	if (guy.getGrade() <= _sign_grade)
		_is_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!(this->isSigned()))
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > _exec_grade)
		throw AForm::GradeTooLowException();
	else
		this->launchExecution();
}

//exceptions
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm exception: grade is too high.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm exception: grade is too low.");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("AForm exception: form is not signed.");
}

//stream redirection
std::ostream &operator<<(std::ostream &os, const AForm& val)
{
	os << val.getName() << ":" << std::endl;
	os << "\tsign grade:\t" << val.getSignGrade() << std::endl;
	os << "\texec grade:\t" << val.getExecGrade() << std::endl;
	os << "\tstate:\t\t";
	if (val.isSigned())
		os << "✅ signed";
	else
		os << "❌ not signed";
	return os;
}
