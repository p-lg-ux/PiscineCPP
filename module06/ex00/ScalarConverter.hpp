/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:53:32 by pgros             #+#    #+#             */
/*   Updated: 2023/06/13 19:21:33 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <sstream>
# include <string>
# include <cmath>
# include <cctype>
# include "macros.hpp"

class ScalarConverter
{
	public:
	static type_t   detectType(std::string literal);
	static void     convert(std::string literal);
	
	private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &other);
	~ScalarConverter();
	ScalarConverter & operator=(ScalarConverter const &rhs);
};

#endif