/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:55:07 by pgros             #+#    #+#             */
/*   Updated: 2023/06/08 18:26:17 by pgros            ###   ########.fr       */
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
};

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
};

ScalarConverter::~ScalarConverter()
{
};

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
    (void)rhs;
	return (*this);
};

void ScalarConverter::convert(std::string literal)
{
	float	c;
	std::istringstream	iss(literal);

	iss >> c;
	if (iss.fail())
		std::cout << "conversion failed" << std::endl;
	else
		std::cout << "float: " << c << std::endl;
}