/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:27:36 by pgros             #+#    #+#             */
/*   Updated: 2023/06/30 20:09:51 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <locale>

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
	std::tm	time = {};
	time_t	tmp_time; 
	char	tmp_char[11];
	std::string	tmp_str;

	//TODO: trim whitespaces of _date
	if (_date.length() != 10 || strptime(_date.c_str(), "%Y-%m-%d", &time) == NULL)
	{
		_errors |= BAD_INPT_DATE;
		return;	
	}
	tmp_time = mktime(&time);
	if (tmp_time < 0)
	{
		_errors |= BAD_INPT_DATE;
		return;
	}
	strftime(tmp_char, 11, "%Y-%m-%d", &time);
	tmp_str = tmp_char;
	// std::cout << "-----------" << std::endl;
	// std::cout << "original: " << _date << std::endl;
	// std::cout << "after mktime: " << tmp_str << std::endl;
	if (_date.find(tmp_str) == std::string::npos)
		_errors |= BAD_INPT_DATE;
	// if (iss.fail() || time.tm_year < 2009 || time.tm_year < 2022)
	// 	_errors |= BAD_INPT_DATE;

	//A MODIFIER AVEC LA STRUCTURE TIME
	// int					val;
	// char				c;
	// std::istringstream	iss(_date);
	
	// iss >> time.tm_year;
	// if (iss.fail() || time.tm_year > 2022 || time.tm_year < 2009)
	// 	_errors |= BAD_INPT_DATE;
	// iss >> c;
	// if (iss.fail() || c != '-')
	// 	_errors |= BAD_INPT_DATE;
	// iss >> time.tm_mon;
	// if (iss.fail() || time.tm_mon > 12 || time.tm_mon < 1)
	// 	_errors |= BAD_INPT_DATE;
	// iss >> c;
	// if (iss.fail() || c != '-')
	// 	_errors |= BAD_INPT_DATE;
	// iss >> time.tm_mday;
	// if (iss.fail() || time.tm_mday > 31 || time.tm_mday < 1)
	// 	_errors |= BAD_INPT_DATE;
}

// void	Input::checkYear();
// void	Input::checkMonth();
// void	Input::checkDay();

void Input::checkValueError()
{
	std::istringstream	iss(_value_str);

	iss >> _value;
	if (iss.fail())
	{
		_errors |= BAD_INPT_VALUE;
		return;
	}
	if (_value < 0)
		_errors |= NEG_VALUE;
	if (_value > 1000)
		_errors |= LARGE_VALUE;
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