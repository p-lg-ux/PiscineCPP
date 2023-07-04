/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:30:13 by pgros             #+#    #+#             */
/*   Updated: 2023/07/04 09:25:53 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <string>
#include <cctype>

//constructors and destructors
RPN::RPN()
{
	//std::cout << "Default constructor of RPN called." << std::endl;
}

RPN::RPN(const RPN& other)
{
(void)other;
	//std::cout << "Copy constructor of RPN called." << std::endl;
}

RPN::~RPN()
{
	//std::cout << "Destructor of RPN called." << std::endl;
}

//overloads
RPN& RPN::operator=(const RPN& rhs)
{
(void)rhs;
	return *this;
}

void RPN::processInput(std::string inpt)
{
	std::string				operators = "+-*/";
	std::string::iterator	it = inpt.begin();
	char					c;
	size_t					oper;

	if (inpt.empty())
		throw ErrorException();
	for (;it != inpt.end(); it++)
	{
		if (it != inpt.begin())
		{
			c = *it++;
			if (c != ' ')
				throw ErrorException();
		}
		c = *it;
		if (std::isdigit(c))
			_stack.push(c - '0');
		else if ((oper = operators.find(c)) != std::string::npos)
			computeOperator(oper);
		else
			throw ErrorException();
	}
}

void RPN::computeOperator(int oper)
{
	OperatorFunc opers[] = {
		&RPN::plus,
		&RPN::minus,
		&RPN::times,
		&RPN::divide,
	};
	int a, b;
	
	if (_stack.size() < 2)
		throw ErrorException();
	b = _stack.top();
	_stack.pop();
	a = _stack.top();
	_stack.pop();
	_stack.push((this->*opers[oper])(a, b));
}


int	RPN::plus(int a, int b)
{
	return (a + b);
}

int	RPN::minus(int a, int b)
{
	return (a - b);
}

int	RPN::times(int a, int b)
{
	return (a * b);
}

int	RPN::divide(int a, int b)
{
	if (b == 0)
		throw ErrorException();
	return (a / b);
}

const char* RPN::ErrorException::what() const throw()
{
	return ("Error");
}
