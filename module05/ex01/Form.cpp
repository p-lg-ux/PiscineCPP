/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:40:50 by pgros             #+#    #+#             */
/*   Updated: 2023/05/30 21:00:09 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
#include <string>

/*class Form
{
	private:
	const std::string	_name;
	bool				_is_signed;
	const int			_sign_grade;
	const int			_exec_grade;

	public:
	//constructors and destructors
	Form();
	Form(const Form& other);
	Form(std::string name, int sign_grade, int exec_grade);
	~Form();
	
	//overloads
	Form& operator=(const Form& rhs);

	//getters
	const std::string 	&getName() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	bool				getIsSigned() const;

	//other member functions
	void	beSigned(Bureaucrat guy);

	//exceptions
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &val);
*/

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

void Form::beSigned(Bureaucrat guy)
{
	
}