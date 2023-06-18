/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:55:07 by pgros             #+#    #+#             */
/*   Updated: 2023/06/18 15:27:51 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

type_t	ScalarConverter::_type = NONE;
char	*ScalarConverter::_charVal = NULL;
int		*ScalarConverter::_intVal = NULL;
float	*ScalarConverter::_floatVal = NULL;
double	*ScalarConverter::_doubleVal = NULL;

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
    (void)rhs;
	return (*this);
}

type_t	ScalarConverter::detectNumberType(std::string &literal)
{
	int		i;
	bool	point = false;

	for (i=0;i < static_cast<int>(literal.length());i++)
	{
		if (literal[i] == '.' && !point && std::isdigit(literal[i + 1]))
		{
			point = true;
			continue;
		}
		else if (std::isdigit(literal[i]))
			continue;
		else
			break;
	}
	if (i == static_cast<int>(literal.length()))
	{
		if (point)
			return (DOUBLE);
		else
			return (INT);
	}
	if (i == static_cast<int>((literal.length() - 1)) && point
		&& literal[literal.length() - 1] == 'f')
		return (FLOAT);
	return (NONE);
}

type_t	ScalarConverter::detectType(std::string literal)
{

	if (literal.empty())
		return (NONE);
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (FLOAT);
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (DOUBLE);
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		return (CHAR);
	if (literal[0] == '-')
		literal = literal.erase(0, 1);
	return (detectNumberType(literal));
}

void	ScalarConverter::convertFromChar(std::istringstream &iss)
{
	_charVal = new char;
	iss >> *_charVal;
	iss >> *_charVal;
	_intVal = new int(static_cast<int>(*_charVal));
	_floatVal = new float(static_cast<float>(*_charVal));
	_doubleVal = new double(static_cast<double>(*_charVal));
	display();
}

void	ScalarConverter::convertFromInt(std::istringstream &iss)
{
	_intVal = new int;
	iss >> *_intVal;
	if (iss.fail())
	{
		std::cerr << "Type not recognized." << std::endl;
		return;
	}
	if (*_intVal >= std::numeric_limits<char>::min() && *_intVal <= std::numeric_limits<char>::max())
		_charVal = new char(static_cast<char>(*_intVal));
	_floatVal = new float(static_cast<float>(*_intVal));
	_doubleVal = new double(static_cast<double>(*_intVal));
	display();
}

void	ScalarConverter::convertFromFloat(std::istringstream &iss)
{
	_floatVal = new float;
	if (iss.str() == "+inff")
		*_floatVal = std::numeric_limits<float>::infinity();
	else if (iss.str() == "-inff")
		*_floatVal = -std::numeric_limits<float>::infinity();
	else if (iss.str() == "nanf")
		*_floatVal = std::numeric_limits<float>::quiet_NaN();
	else
		iss >> *_floatVal;
	if (iss.fail())
	{
		std::cerr << "Type not recognized." << std::endl;
		return;
	}
	if (*_floatVal >= std::numeric_limits<char>::min() && *_floatVal <= std::numeric_limits<char>::max())
		_charVal = new char(static_cast<char>(*_floatVal));
	if (*_floatVal >= std::numeric_limits<int>::min() && *_floatVal <= std::numeric_limits<int>::max())
		_intVal = new int(static_cast<int>(*_floatVal));
	_doubleVal = new double(static_cast<double>(*_floatVal));
	display();
}

void	ScalarConverter::convertFromDouble(std::istringstream &iss)
{
	_doubleVal = new double;
	if (iss.str() == "+inf")
		*_doubleVal = std::numeric_limits<double>::infinity();
	else if (iss.str() == "-inf")
		*_doubleVal = -std::numeric_limits<double>::infinity();
	else if (iss.str() == "nan")
		*_doubleVal = std::numeric_limits<double>::quiet_NaN();
	else
		iss >> *_doubleVal;
	if (iss.fail())
	{
		std::cerr << "Type not recognized." << std::endl;
		return;
	}
	if (*_doubleVal >= std::numeric_limits<char>::min() && *_doubleVal <= std::numeric_limits<char>::max())
		_charVal = new char(static_cast<char>(*_doubleVal));
	if (*_doubleVal >= std::numeric_limits<int>::min() && *_doubleVal <= std::numeric_limits<int>::max())
		_intVal = new int(static_cast<int>(*_doubleVal));
	_floatVal = new float(static_cast<float>(*_doubleVal));
	display();
}

void	ScalarConverter::convertNone(std::istringstream &iss)
{
	(void)iss;
	std::cerr << "Type not recognized." << std::endl;
}

void	ScalarConverter::deleteAttributes()
{
	if (_charVal != NULL)
		delete _charVal;
	if (_intVal != NULL)
		delete _intVal;
	if (_floatVal != NULL)
		delete _floatVal;
	if (_doubleVal != NULL)
		delete _doubleVal;
}

void ScalarConverter::convert(std::string literal)
{
	std::istringstream	iss(literal);
	convertFunc f[5] = {
		&ScalarConverter::convertFromChar,
		&ScalarConverter::convertFromInt,
		&ScalarConverter::convertFromFloat,
		&ScalarConverter::convertFromDouble,
		&ScalarConverter::convertNone,
	};

	f[detectType(literal)](iss);
	deleteAttributes();
}

void	ScalarConverter::display()
{
	displayChar();
	displayInt();
	displayFloat();
	displayDouble();
}

void ScalarConverter::displayChar()
{
	std::cout << "char: ";
	if (_charVal == NULL)
		std::cout << "impossible" << std::endl;
	else
	{
		if (*_charVal >= 32 && *_charVal <= 126)
			std::cout << "'" << *_charVal << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
}

void ScalarConverter::displayInt()
{
	std::cout << "int: ";
	if (_intVal == NULL)
		std::cout << "impossible" << std::endl;
	else
		std::cout << *_intVal << std::endl;
}

void ScalarConverter::displayFloat()
{
	std::cout << "float: ";
	if (_floatVal == NULL)
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << *_floatVal << "f" << std::endl;
}

void ScalarConverter::displayDouble()
{
	std::cout << "double: ";
	if (_doubleVal == NULL)
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << *_doubleVal << std::endl;
}