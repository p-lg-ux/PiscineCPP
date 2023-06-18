/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:40:57 by pgros             #+#    #+#             */
/*   Updated: 2023/06/18 14:26:37 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	std::string str;
	if (argc != 2)
	{
		std::cerr << "One argument required." << std::endl;
		return (1);
	}
	// std::cout << "char: [ " << (int)std::numeric_limits<char>::min() << " ; " << (int)std::numeric_limits<char>::max() << " ]" << std::endl;
	// std::cout << "int: [ " << std::numeric_limits<int>::min() << " ; " << std::numeric_limits<int>::max() << " ]" << std::endl;
	// std::cout << "float: [ " << std::numeric_limits<float>::min() << " ; " << std::numeric_limits<float>::max() << " ]" << std::endl;
	// std::cout << "double: [ " << std::numeric_limits<double>::min() << " ; " << std::numeric_limits<double>::max() << " ]" << std::endl;
	// str = argv[1];
	ScalarConverter::convert(argv[1]);
	return (0);
}