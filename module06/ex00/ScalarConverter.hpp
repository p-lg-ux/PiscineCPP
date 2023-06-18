/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:53:32 by pgros             #+#    #+#             */
/*   Updated: 2023/06/18 15:16:51 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <sstream>
# include <string>
# include <iomanip>
# include <cmath>
# include <limits>
# include "macros.hpp"

class ScalarConverter
{
	typedef			void (*convertFunc)(std::istringstream &iss);
	
	public:
	
	static type_t   detectType(std::string literal);
	static type_t	detectNumberType(std::string &literal);	
	
	static void     convert(std::string literal);
	static void     convertFromChar(std::istringstream &iss);
	static void     convertFromInt(std::istringstream &iss);
	static void     convertFromFloat(std::istringstream &iss);
	static void     convertFromDouble(std::istringstream &iss);
	static void     convertNone(std::istringstream &iss);

	static void		deleteAttributes();
	
	static void		display();
	static void		displayChar();
	static void		displayInt();
	static void		displayFloat();
	static void		displayDouble();

	private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &other);
	~ScalarConverter();
	ScalarConverter& 	operator=(ScalarConverter const &rhs);
	static type_t		_type;
	static char			*_charVal;
	static int			*_intVal;
	static float		*_floatVal;
	static double		*_doubleVal;
};

#endif