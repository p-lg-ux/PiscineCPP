/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:55:07 by pgros             #+#    #+#             */
/*   Updated: 2023/06/13 19:22:54 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
class ScalarConverter
{
    public:
    convert(std::string literal);
    
    private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &other);
    ~ScalarConverter();
    ScalarConverter & operator=(ScalarConverter const &rhs);
};
*/

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
    (void)rhs;
	return (*this);
}

type_t	ScalarConverter::detectType(std::string literal)
{
	bool	point = false;
	int		i;

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
	for (i=0;i <(int)literal.length();i++)
	{
		if (literal[i] == '.'
			&& !point
			&& std::isdigit(literal[i + 1]))
		{
			point = true;
			continue;
		}
		else if (std::isdigit(literal[i]))
			continue;
		else
			break;
	}
	if (i == (int)literal.length())
	{
		if (point)
			return (DOUBLE);
		else
			return (INT);
	}
	if (i == (int)(literal.length() - 1)
		&& point
		&& literal[literal.length() - 1] == 'f')
		return (FLOAT);
	return (NONE);
}


void ScalarConverter::convert(std::string literal)
{
	float	c;
	std::istringstream	iss(literal);

	c = detectType(literal);
	std::cout << literal << std::endl;
	if (c == INT)
		std::cout << "int detected" << std::endl;
	else if (c == CHAR)
		std::cout << "char detected" << std::endl;
	else if (c == FLOAT)
		std::cout << "float detected" << std::endl;
	else if (c == DOUBLE)
		std::cout << "double detected" << std::endl;
	else
		std::cout << "none detected" << std::endl;		
	iss >> c;
	c = NAN;
	if (iss.fail())
		std::cout << "conversion failed" << std::endl;
	// else
	std::cout << "float: " << c << std::endl;
}