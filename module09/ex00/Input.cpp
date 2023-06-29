/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:27:36 by pgros             #+#    #+#             */
/*   Updated: 2023/06/29 21:38:34 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"
#include <iostream>
#include <string>

//constructors and destructors
Input::Input()
{
}

Input::Input(char delim) : _delimiter(delim)
{
}

Input::Input(const Input& other)
{
 	*this = other;
}
Input::~Input()
{
}

//overloads
Input& Input::operator=(const Input& rhs)
{
	_line = rhs.getLine();
	_delimiter = rhs.getDelimiter();
	_date = rhs.getDate();
	_value = rhs.getValue();
	_errors = rhs.getErrors();
	return *this;
}

//getters
char Input::getDelimiter() const
{
	return (_delimiter);
}

std::string Input::getLine() const
{
	return (_line);
}

dateString_t Input::getDate() const
{
	return (_date);
}

valueString_t Input::getValueStr() const
{
	return (_value_str);
}

float Input::getValue() const
{
	return (_value);
}

error_t Input::getErrors() const
{
	return (_errors);
}

bool Input::splitLine()
{
	size_t	delim_pos = _line.find(_delimiter);
	if (delim_pos == std::string::npos)
	{
		_errors |= NO_DELIM;
		return (false);
	}
	_date = _line.substr(0, delim_pos);
	_value_str = _line.substr(delim_pos + 1);
	return (true);
}

void Input::checkDateError()
{
	//A MODIFIER AVEC LA STRUCTURE TIME
	// std::istringstream	iss(_date);
	// int					val;
	// char				c;
	
	// iss >> val;
	// if (iss.fail() || val > 2022 || val < 2009)
	// 	_errors |= BAD_INPT_DATE;
	// iss >> c;
	// if (iss.fail() || c != 'c')
	// 	_errors |= BAD_INPT_DATE;
	// iss >> val;
	// if (iss.fail() || val > 12 || val < 1)
	// 	_errors |= BAD_INPT_DATE;
	// iss >> c;
	// if (iss.fail() || c != 'c')
	// 	_errors |= BAD_INPT_DATE;
	
}

void	Input::checkYear();
void	Input::checkMonth();
void	Input::checkDay();

void Input::checkValueError()
{
	// [...]
}

Input& Input::operator=(std::string& line)
{
	_line = line;
	_errors = NO_ERROR;
	if (splitLine())
	{
		checkDateError();
		// checkValueError();		
	}
	return *this;
}